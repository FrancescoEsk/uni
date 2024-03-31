module MorraCinese (
    input clk, // clock
    input reg [1:0] primo,
    input reg [1:0] secondo,
    input inizio, 
    
    output reg [1:0] manche,
    output reg [1:0] partita,
    output reg [2:0] stato // TEMPORANEO
);

    reg [2:0] stato_prossimo; // scegliere i bit in base a quanti stati vogliamo avere

    reg [4:0] max; // contiene le partite massime giocabili (diminuiusce ogni manche valida effettuata)
    reg [4:0] count; // conta quante partite sono state giocate
    reg [3:0] vant; // vantaggio 
    reg [1:0] oldPrimo; // registro per salvare la mossa precedente
    reg [1:0] oldSecondo; // registro per salvare la mossa precedente

    bit manchex; // 1 = manche non valida, 0 = manche valida
    bit finex; // 1 = partita da terminare obbligatoriamente, 0 = no
    bit minx; // 1 = minimo di 4 partite raggiunto, 0 = no
    bit vantm; // attivo se uno dei due giocatori e' in vantaggio schiacciante (vittora non concedibile per minimo partite)

    always @(posedge clk) begin // INIZIO / RESET
        if (inizio) begin
            // contare partite massime da giocare - parentesi graffe concatenano (10 01 --> 1001)
            max = 5'b00100 + {primo, secondo};
            // AZZERO
            oldPrimo = 2'b00;
            oldSecondo = 2'b00;
            // vant --> considero 1000 come pareggio, e rispettivamente >1000 per 1 e <1000 per 2
            vant = 4'b1000; 
            count = 5'b00000;
            manchex = 1'b0;
            finex = 1'b0;
            minx = 1'b0;
            vantm = 1'b0;

            stato_prossimo = 3'b000; // bit di stato iniziale 
        end else begin
            stato = stato_prossimo; // se non ho reset, aggiorno lo stato
        end
    end

    always @(primo, secondo, count, vant, oldPrimo, oldSecondo) begin : DATAPATH
        if(count >= 5'b00100) // PARTITE GIOCATE < 4
            minx = 1'b1;
        
        if (count == max) // MASSIMO PARTITE RAGGIUNTO
            finex = 1'b1;
        
        // se uno dei due giocatori e' in vantaggio di 2 o piu'
        if (vant > 4'b1001 || vant < 4'b0110) 
            vantm = 1'b1;
        else
            vantm = 1'b0;

        // se il giocatore vincente ripete la mossa precedente oppure 
        // un giocatore inserisce 00 la manche non e' valida
        if (primo == oldPrimo || secondo == oldSecondo || 
            primo == 2'b00 || secondo == 2'b00)
            manchex = 1'b1;
        else
            manchex = 1'b0;
        
    end

    always @(primo, secondo, inizio) begin : FSM
        case(stato)
            3'b000: begin // stato INIZIO
                manche = 2'b00;
                partita = 2'b00;
                stato_prossimo = 3'b001; // stato PAREGGIO
            end

            3'b001: begin // stato PAREGGIO
                if (inizio == 1'b0) begin // se non c'e' reset

                    if(finex) begin // TERMINARE PARTITA in PAREGGIO
                        partita = 2'b11;
                        stato_prossimo = 3'b100; //stato FINE PARTITA
                    end

                    else if (manchex) begin // MOSSE NON VALIDE
                        manche = 2'b00;
                        partita = 2'b00;
                        stato_prossimo = 3'b001; //stato PAREGGIO
                    end else begin // MOSSE VALIDE
                        if (primo == 2'b10 && secondo == 2'b01
                        || primo == 2'b01 && secondo == 2'b11
                        || primo == 2'b11 && secondo == 2'b10) begin
                            // VINCE 1
                            manche = 2'b01;
                            partita = 2'b00;
                            stato_prossimo = 3'b010; // stato VANT 1 
                        end else if (primo == 2'b01 && secondo == 2'b10
                        || primo == 2'b11 && secondo == 2'b01
                        || primo == 2'b10 && secondo == 2'b11) begin
                            // VINCE 2
                            manche = 2'b10;
                            partita = 2'b00;
                            stato_prossimo = 3'b011; // stato VANT 2 
                        end else if (primo == secondo) begin
                            // PAREGGIO
                            manche = 2'b11;
                            partita = 2'b00;
                            stato_prossimo = 3'b001; // stato PAREGGIO
                        end
                    end

                end else begin
                    manche = 2'b00;
                    partita = 2'b00;
                    stato_prossimo = 3'b000; // stato INIZIO
                end
                
            end

            3'b010: begin // stato VANT 1
                if (inizio == 1'b0) begin // se non c'e' reset

                    if((minx && vantm) || finex ) begin // TERMINARE PARTITA in VITTORIA 1
                        partita = 2'b01;
                        stato_prossimo = 3'b100; //stato FINE PARTITA
                    end

                    else if (manchex) begin // MOSSE NON VALIDE
                        manche = 2'b00;
                        partita = 2'b00;
                        stato_prossimo = 3'b010; //stato VANT 1
                    end else begin // MOSSE VALIDE
                        if (primo == 2'b10 && secondo == 2'b01
                        || primo == 2'b01 && secondo == 2'b11
                        || primo == 2'b11 && secondo == 2'b10) begin
                            // VINCE 1
                            manche = 2'b01;
                            partita = 2'b00;
                            stato_prossimo = 3'b010; // stato VANT 1 
                        end else if (primo == 2'b01 && secondo == 2'b10
                        || primo == 2'b11 && secondo == 2'b01
                        || primo == 2'b10 && secondo == 2'b11) begin
                            // VINCE 2
                            manche = 2'b10;
                            partita = 2'b00;
                            stato_prossimo = 3'b001; // stato PAREGGIO 
                        end else if (primo == secondo) begin
                            // PAREGGIO
                            manche = 2'b11;
                            partita = 2'b00;
                            stato_prossimo = 3'b010; // stato VANT 1
                        end
                    end

                end else begin
                    manche = 2'b00;
                    partita = 2'b00;
                    stato_prossimo = 3'b000; // stato INIZIO
                end
            end

            3'b011: begin // stato VANT 2
                if (inizio == 1'b0) begin // se non c'e' reset

                    if((minx && vantm) || finex ) begin // TERMINARE PARTITA in VITTORIA 2
                        partita = 2'b10;
                        stato_prossimo = 3'b100; //stato FINE PARTITA
                    end

                    else if (manchex) begin // MOSSE NON VALIDE
                        manche = 2'b00;
                        partita = 2'b00;
                        stato_prossimo = 3'b011; //stato VANT 2
                    end else begin // MOSSE VALIDE
                        if (primo == 2'b10 && secondo == 2'b01
                        || primo == 2'b01 && secondo == 2'b11
                        || primo == 2'b11 && secondo == 2'b10) begin
                            // VINCE 1
                            manche = 2'b01;
                            partita = 2'b00;
                            stato_prossimo = 3'b001; // stato PAREGGIO 
                        end else if (primo == 2'b01 && secondo == 2'b10
                        || primo == 2'b11 && secondo == 2'b01
                        || primo == 2'b10 && secondo == 2'b11) begin
                            // VINCE 2
                            manche = 2'b10;
                            partita = 2'b00;
                            stato_prossimo = 3'b011; // stato VANT 2 
                        end else if (primo == secondo) begin
                            // PAREGGIO
                            manche = 2'b11;
                            partita = 2'b00;
                            stato_prossimo = 3'b011; // stato VANT 2
                        end
                    end

                end else begin
                    manche = 2'b00;
                    partita = 2'b00;
                    stato_prossimo = 3'b000; // stato INIZIO
                end
            end

            3'b100: begin // stato FINE
                stato_prossimo = 3'b100; // stato FINE
            end
        endcase 
    end

    always @(manche) begin : RIENTRI_DATAPATH
        case (manche) 
            2'b01: begin // manche vinta da 1
                oldPrimo = primo; // salvo mossa di 1
                oldSecondo = 2'b00; // 2 puo' giocare qualunque mossa
                count++; // conto la manche
                vant++; // do' punto ad 1
            end
            2'b10: begin // manche vinta da 2
                oldSecondo = secondo; // salvo mossa di 2
                oldPrimo = 2'b00; // 1 puo' giocare qualunque mossa
                count++; // conto la manche
                vant--; // do' punto ad 2
            end
            2'b11: begin // manche pareggiata
                oldPrimo = 2'b00; // 1 puo' giocare qualunque mossa
                oldSecondo = 2'b00; // 2 puo' giocare qualunque mossa
                count++; // conto la manche
                // do' punto a nessuno
            end
        endcase
    end

    /*
    RICORDO
    - se un giocatore inserisce 00 come mossa, la manche non e' valida e quindi non viene contata
    - vantm e' attivo solo nel caso un giocatore fosse in vantaggio di 2 o piu'
    - oldPrimo e oldSecondo, se valgono 00 significa che il giocatore puo' giocare qualunque mossa
    - 
    */
endmodule 