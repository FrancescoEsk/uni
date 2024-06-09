module MorraCinese (
    // INPUTS
    input clk, // clock
    input reg [1:0] PRIMO,
    input reg [1:0] SECONDO,
    input INIZIO, 

    // OUTPUTS
    output reg [1:0] MANCHE,
    output reg [1:0] PARTITA
);
    // registri
    reg [2:0] stato;
    reg [2:0] stato_prossimo;

    reg [1:0] MOSSA_PREC;
    reg [1:0] VINCITORE_PREC;
    reg [4:0] COUNT;
    reg [4:0] MAX;

    // bit
    bit COUNT_MIN;
    bit COUNT_MAX;
    bit NO_VALID;

    // bit locale
    bit m; // usato per calcolare se la manche la vince 1 oppure no

    always @(posedge clk) begin // INIZIO / RESET
        if (INIZIO == 1'b1) begin
            stato = 3'b000; // stato iniziale

            // imposto tutti i registri al valore iniziale
            MOSSA_PREC = 2'b00;
            VINCITORE_PREC = 2'b00;
            COUNT = 5'b00000;
            MAX = 5'b00011 + {PRIMO, SECONDO};
            // anche i bit
            COUNT_MIN = 1'b0;
            COUNT_MAX = 1'b0;
            NO_VALID = 1'b0;

        end else begin
            // se non ho reset, aggiorno lo stato
            stato = stato_prossimo; 
        end
    end

    always @(PRIMO, SECONDO) begin : DATAPATH
        // calcolo NO_VALID
        case(VINCITORE_PREC)
            default:
                NO_VALID = 1'b0;
        
            2'b01:  // controllo PRIMO
                if (PRIMO == MOSSA_PREC ) begin
                    $display("\nNon valido 1\n");
                    NO_VALID = 1'b1;
                end else begin
                    NO_VALID = 1'b0;
                end
           
            2'b10:  // controllo SECONDO
                if (SECONDO == MOSSA_PREC ) begin
                    $display("\nNon valido 2\n");
                    NO_VALID = 1'b1;
                end else begin
                    NO_VALID = 1'b0;
                end
        endcase
            
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

    always @(stato, PRIMO, SECONDO, INIZIO, NO_VALID, COUNT_MIN, COUNT_MAX) begin : FSM
        $display("\nVincitore prec: %b \\ Mossa prec: %b", VINCITORE_PREC, MOSSA_PREC);
        $display("NO_VALID: %b \\ COUNT_MIN: %b \\ COUNT_MAX: %b\n", NO_VALID, COUNT_MIN, COUNT_MAX);
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
        
        if (PRIMO == 2'b10 && SECONDO == 2'b01
            || PRIMO == 2'b01 && SECONDO == 2'b11
            || PRIMO == 2'b11 && SECONDO == 2'b10) begin

            m = 1'b1; // vale 1 se vince la manche 1, vale 0 se vince la manche 2
        end else begin
            m = 1'b0;
        end

        case(stato)
            // INIZIO
            3'b000: begin 
                if(INIZIO) begin // INIZIO VALE 1 - AVANZO
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
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(COUNT_MAX) begin // partita da finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b11;
                            stato_prossimo = 3'b000; // inizio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end
                    end else begin // partita da non finire
                        PARTITA = 2'b00;
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            stato_prossimo = 3'b001; // pareggio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            stato_prossimo = 3'b010; // v1
                        end else begin
                            MANCHE = 2'b01;
                            stato_prossimo = 3'b101; // v2
                        end
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b001; // pareggio
                end
            end
            
            // V1
            3'b010: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(COUNT_MAX) begin // partita da finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b11;
                            stato_prossimo = 3'b000; // inizio
                        end
                    end else begin // partita da non finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b010; // v1
                        end else if (m) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b10;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b011; // v1+
                            end else begin
                                MANCHE = 2'b10;
                                PARTITA = 2'b10;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b001; // pareggio
                        end
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b010; // v1
                end
            end

            // V1+
            3'b011: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(COUNT_MAX) begin // partita da finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b10;
                            stato_prossimo = 3'b000; // inizio
                        end
                    end else begin // partita da non finire
                        if(PRIMO == SECONDO) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b11;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b011; // v1+
                            end else begin
                                MANCHE = 2'b11;
                                PARTITA = 2'b10;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else if (m) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b10;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b100; // v1++
                            end else begin
                                MANCHE = 2'b10;
                                PARTITA = 2'b10;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b010; // v1
                        end
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b011; // v1+
                end
            end

            // V1++
            3'b100: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(PRIMO == SECONDO) begin
                        MANCHE = 2'b11;
                        PARTITA = 2'b10;
                        stato_prossimo = 3'b000; // inizio
                    end else if (m) begin
                        MANCHE = 2'b10;
                        PARTITA = 2'b10;
                        stato_prossimo = 3'b000; // inizio
                    end else begin
                        MANCHE = 2'b01;
                        PARTITA = 2'b10;
                        stato_prossimo = 3'b000; // inizio
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b100; // v1++
                end
            end

            // V2
            3'b101: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(COUNT_MAX) begin // partita da finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b11;
                            stato_prossimo = 3'b000; // inizio
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end
                    end else begin // partita da non finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b101; // v2
                        end else if (!m) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b01;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b110; // v2+
                            end else begin
                                MANCHE = 2'b01;
                                PARTITA = 2'b01;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b001; // pareggio
                        end
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b101; // v2
                end
            end

            // V2+
            3'b110: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(COUNT_MAX) begin // partita da finire
                        if(PRIMO == SECONDO) begin
                            MANCHE = 2'b11;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end else if (m) begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end else begin
                            MANCHE = 2'b01;
                            PARTITA = 2'b01;
                            stato_prossimo = 3'b000; // inizio
                        end
                    end else begin // partita da non finire
                        if(PRIMO == SECONDO) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b11;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b110; // v2+
                            end else begin
                                MANCHE = 2'b11;
                                PARTITA = 2'b01;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else if (!m) begin
                            if (COUNT_MIN) begin
                                MANCHE = 2'b01;
                                PARTITA = 2'b00;
                                stato_prossimo = 3'b111; // v2++
                            end else begin
                                MANCHE = 2'b01;
                                PARTITA = 2'b01;
                                stato_prossimo = 3'b000; // inizio
                            end
                        end else begin
                            MANCHE = 2'b10;
                            PARTITA = 2'b00;
                            stato_prossimo = 3'b101; // v2
                        end
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b110; // v2+
                end
            end

            // V2++
            3'b111: begin
                if (INIZIO) begin
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b000; // inizio
                end else if (NO_VALID == 1'b0) begin // mosse valide
                    if(PRIMO == SECONDO) begin
                        MANCHE = 2'b11;
                        PARTITA = 2'b01;
                        stato_prossimo = 3'b000; // inizio
                    end else if (m) begin
                        MANCHE = 2'b10;
                        PARTITA = 2'b01;
                        stato_prossimo = 3'b000; // inizio
                    end else begin
                        MANCHE = 2'b01;
                        PARTITA = 2'b01;
                        stato_prossimo = 3'b000; // inizio
                    end
                end else begin // mosse non valide
                    MANCHE = 2'b00;
                    PARTITA = 2'b00;
                    stato_prossimo = 3'b111; // v2++
                end
            end
        endcase
    end

    always @(posedge clk) begin : RIENTRI_DATAPATH
        case(MANCHE)

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
                MOSSA_PREC = 2'b00;

                // AGGIORNO VINCITORE_PREC
                VINCITORE_PREC = 2'b00;

                // AUMENTO COUNT
                COUNT = COUNT + 5'b00001;
            end

            2'b00: begin
                VINCITORE_PREC = VINCITORE_PREC;
                MOSSA_PREC = MOSSA_PREC;
            end

        endcase
    end

endmodule
