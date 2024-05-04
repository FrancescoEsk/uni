module MorraCinese (
    // INPUTS
    input clk, // clock
    input reg [1:0] PRIMO,
    input reg [1:0] SECONDO,
    input INIZIO, 
    
    // OUTPUTS
    output reg [1:0] MANCHE,
    output reg [1:0] PARTITA,
);
    // registri
    reg [2:0] stato;
    reg [2:0] stato_prossimo;

    reg [1:0] MOSSA_PREC;
    reg [1:0] VINCITORE_PREC;
    reg [4:0] COUNT;
    reg [4:0] MAX;
    reg [2:0] stato_prossimo;
    
    // bit
    bit COUNT_MIN;
    bit COUNT_MAX;
    bit NO_VALID;

    // bit locale
    bit m; // usato per calcolare se la manche la vince 1 oppure no

    always @(posedge clk) begin // INIZIO / RESET
        if (INIZIO) begin
            // imposto tutti i registri al valore iniziale
            MOSSA_PREC = 2'b00;
            VINCITORE_PREC = 2'b00;
            COUNT = 5'b00000;
            MAX = 5'b00011 + {primo, secondo};

            stato_prossimo = 3'b000; // bit di stato iniziale 
        end else begin
            // se non ho reset, aggiorno lo stato
            stato = stato_prossimo; 
        end
    end

    always @(PRIMO, SECONDO, INIZIO) begin : DATAPATH
        // calcolo NO_VALID
        case(VINCITORE_PREC) begin
            2'b01: begin // controllo PRIMO
                if (PRIMO == 2'b00 || SECONDO == 2'b00 || PRIMO == MOSSA_PREC ) 
                    NO_VALID = 1'b1;
            end
            2'b10: begin // controllo SECONDO
                if (PRIMO == 2'b00 || SECONDO == 2'b00 || SECONDO == MOSSA_PREC ) 
                    NO_VALID = 1'b1;
            end
            default: // LASCIO PASSARE
                NO_VALID = 1'b0;
        end
        
        // calcolo COUNT_MIN
        if(5'b00011 >= COUNT) // se count minore di 3 (4 partite)
            COUNT_MIN = 1'b1; 
        else // altrimenti
            COUNT_MIN = 1'b0;

        // calcolo COUNT_MAX
        if(COUNT >= MAX) // se count maggiore o uguale di max (massimo partite giocabili raggiunto)
            COUNT_MAX = 1'b1; 
        else // altrimenti
            COUNT_MAX = 1'b0;

    end

    always @(MANCHE) begin : RIENTRI_DATAPATH
        case(MANCHE) begin
            
            2'b01: begin // CASO MANCHE VINTA DA 1
                // AGGIORNO MOSSA_PREC
                MOSSA_PREC = PRIMO;

                // AGGIORNO VINCITORE_PREC
                VINCITORE_PREC = 2'b01;

                // AUMENTO COUNT
                COUNT = COUNT + 5'b00001;
            end

            2'b10: begin // CASO MANCHE VINTA DA 2
                // AGGIORNO MOSSA_PREC
                MOSSA_PREC = SECONDO;

                // AGGIORNO VINCITORE_PREC
                VINCITORE_PREC = 2'b10;
                
                // AUMENTO COUNT
                COUNT = COUNT + 5'b00001;
            end

            2'b11: begin // CASO MANCHE PAREGGIATA
                // AGGIORNO MOSSA_PREC
                MOSSA_PREC = 2'b11;

                // AGGIORNO VINCITORE_PREC
                VINCITORE_PREC = 2'b11;
                
                // AUMENTO COUNT
                COUNT = COUNT + 5'b00001;
            end

        end
    end

    always @(NO_VALID, COUNT_MIN, COUNT_MAX) begin : FSM
        /*
        # CODIFICA DEGLI STATI
        INIZIA 000 # Stato di INIZIA
        PAREGGIO 001 # Stato di pareggio
        V1 010 # Stato di vantaggio 1 (+1)
        V1P 011 # Stato di vantaggio di 1 (+2)
        V1PP 100 # Stato di vantaggio di 1 (+3)
        V2 101 # Stato di vantaggio di 2 (+1)
        V2P 110 # Stato di vantaggio di 2 (+2)
        V2PP 111 # Stato di vantaggio di 2 (+3)
        */

        if (primo == 2'b10 && secondo == 2'b01
            || primo == 2'b01 && secondo == 2'b11
            || primo == 2'b11 && secondo == 2'b10) begin

            m = 1'b1; // vale 1 se vince la manche 1, vale 0 se vince la manche 2
        end else begin
            m = 1'b0;
        end

        case(stato) begin
            // INIZIO
            3'b000: begin 
                if(INIZIO == 1'b1) begin // INIZIO VALE 1 - AVANZO
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b001; // MANDO A STATO PAREGGIO
                end else begin // INIZIO VALE 0 - RIMANGO
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // MANDO A STATO INIZIALE
                end
            end

            // PAREGGIO
            3'b001: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    // VINCE 1 e COUNT_MAX ATTIVO - VITTORIA 1
                    if (COUNT_MAX == 1'b1) begin 
                        MANCHE = 2'b01;
                        PARTITA = 2'b01;
                        stato_prossimo = 3'b000; // MANDO A STATO INIZIALE
                    end else begin
                    // VINCE 1 - MANCHE 1
                        MANCHE = 2'b01;
                        PARTITA = 2'b00;
                        stato_prossimo = 3'b010; // MANDO A STATO V1
                    end
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        // PAREGGIO e COUNT_MAX ATTIVO - PAREGGIO 11
                        if (COUNT_MAX == 1'b1) begin 
                            MANCHE = 2'b11;
                            PARTITA = 2'b11;
                            stato_prossimo = 3'b000; // MANDO A STATO INIZIALE
                        end else begin
                            // PAREGGIO e NO_VALID ATTIVO - NON VALIDO 00
                            if(NO_VALID == 1'b1) begin
                                MANCHE = 2'b00;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b001; // MANDO A STATO PAREGGIO
                            end
                        end
                        
                    end else begin // MANCHE VINTA DA 2
                        // VINCE 2 e COUNT_MAX ATTIVO - VITTORIA 2
                        if (COUNT_MAX == 1'b1) begin 
                            MANCHE = 2'b10;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // MANDO A STATO INIZIALE
                        end else begin 
                           // VINCE 2 - MANCHE 2
                            MANCHE = 2'b10;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b101; // MANDO A STATO v2 
                        end
                    end
                end
            end
            
            // V1
            3'b010: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    // VINCE 1 e COUNT_MIN ATTIVO - MANCHE 1
                    if(COUNT_MIN == 1'b1) begin
                        MANCHE = 2'b01;
                        PARTITA = 2'b00;
                        stato_prossimo = 3'b011; // MANDO A STATO V1+
                    end
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        

                    end else begin // MANCHE VINTA DA 2
                        
 

                    end
                end
            end

            // V1+
            3'b011: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        
                        
                    end else begin // MANCHE VINTA DA 2
                        


                    end
                end
            end

            // V1++
            3'b100: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        
                        
                    end else begin // MANCHE VINTA DA 2
                        


                    end
                end
            end

            // V2
            3'b101: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        
                        
                    end else begin // MANCHE VINTA DA 2
                        


                    end
                end
            end

            // V2+
            3'b110: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        
                        
                    end else begin // MANCHE VINTA DA 2
                        


                    end
                end
            end

            // V2++
            3'b111: begin
                if(m == 1'b1) begin // MANCHE VINTA DA 1
                    
                    
                    
                end else begin
                    if(PRIMO == SECONDO ) begin // MANCHE PAREGGIATA
                        
                        
                        
                    end else begin // MANCHE VINTA DA 2
                        


                    end
                end
            end

        end
    end

endmodule
