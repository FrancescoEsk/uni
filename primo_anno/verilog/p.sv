module MorraCinese (
    input clk,               // segnale di clock
    input reg[1:0] primo,    // input della scelta del primo giocatore
    input reg[1:0] secondo,  // input della scelta del secondo giocatore
    input inizia,            // bit che mi funziona da reset
    output reg[1:0] manche,      // output che mi dice come è andata la manche
    output reg[1:0] partita,     // output che mi dice come è andata la partita
    output reg[3:0] stato
);
  	reg[4:0] n_manche;       // registro adibito a tenere il numero massimo di manche
  	reg[4:0] count_manche;   // registro adibito per tenere il conto delle manche giocate
    reg[4:0] count1;         // registro che conta il punteggio del primo giocatore
    reg[4:0] count2;         // registro che conta il punteggio del secondo giocatore
    reg[3:0] stato_prossimo; // registro per salvare lo stato prossimo in base agli input
    reg[1:0] vincitore_prec; // registro per salvare vincitore precedente
    reg[1:0] mossa_prec;     // registro per salvare la mossa del vincitore precedente
  
  	// bit provenienti dal Datapth
    bit vantaggio_mag_1_2; 
  	bit vantaggio_mag_2_2;
    bit forza_fine;         // bit utilizzato per forzare la fine di una partita
    bit mosse_valide;       
  	bit terminabile;

    always @(posedge clk) begin : UPDATE
        if(inizia) begin
            stato = 3'b000;                       // setto come stato iniziale INIZIA
            n_manche = {primo, secondo} + 3'b100; // setto il numero di manche massime da giocare
            count1 = 5'b00000;                    // setto il punteggio del primo giocatore a 0
            count2 = 5'b00000;                    // setto il punteggio del secondo giocatore a 0
            count_manche = 5'b00000;              // setto il contatore delle manche giocate a 0
          	forza_fine = 1'b0;
          	mosse_valide = 1'b0;
          	terminabile = 1'b0;
          	vantaggio_mag_1_2 = 1'b0;
          	vantaggio_mag_2_2 = 1'b0;
        end else begin
            stato = stato_prossimo;               // metto come stato il valore del prossimo stato
        end
    end


  always @(count1, count2,count_manche,vincitore_prec,mossa_prec) begin : DATAPATH
      
    if(count_manche == n_manche) begin
        forza_fine = 1'b1; // bit per forzare la fine del gioco
    end
    
    if(count_manche > 3) begin
      	terminabile = 1'b1;
   	end
   
    if(count1 >= (count2 + 2)) begin // bit per controllare eventuali vantaggi >= 2
   		vantaggio_mag_1_2 = 1'b1;
    end else begin
      	vantaggio_mag_1_2 = 1'b0;
    end
    
    if(count2 >= (count1 + 2)) begin
      	vantaggio_mag_2_2 = 1'b1;
    end else begin
        vantaggio_mag_2_2 = 1'b0;
    end   
    
    
        case(vincitore_prec)
            2'b01:
                if(primo == mossa_prec) begin
                    mosse_valide <= 1'b0;
                end else begin
                    mosse_valide <= 1'b1;
                end
            
            2'b10:
                if(secondo == mossa_prec) begin
                    mosse_valide <= 1'b0;
                end else begin
                    mosse_valide <= 1'b1;
                end

            default:
                mosse_valide <= 1'b1; 
        endcase
    
    end


    always @(stato, primo, secondo, inizia) begin : FSM
        case (stato)
            3'b000:  begin// stato di reset
              manche = 2'b00;            // nessuno ha (chiaramente) vinto la manche
         		partita = 2'b00;         // nessuno ha ancora vinto la partita
                stato_prossimo = 3'b011; // inizio la partita nello stato di pareggio
            end
                
            3'b001: // stato di vantaggio del giocatore 1
              if(inizia) begin
                manche = 2'b00;
                partita = 2'b00;
                stato_prossimo = 3'b000;
              end else if(forza_fine || (terminabile && vantaggio_mag_1_2)) begin
                manche = vincitore_prec;
                partita = 2'b01;
                stato_prossimo = 3'b100;
              end else begin
                if(mosse_valide) begin
                	if(primo == 2'b01 && secondo == 2'b11 ||
                         primo == 2'b10 && secondo == 2'b01 ||
                         primo == 2'b11 && secondo == 2'b10) begin
                         manche = 2'b01;
                         partita = 2'b00;
                         stato_prossimo = 3'b001;
               		 end else if(secondo == 2'b01 && primo == 2'b11 ||
                   		 secondo == 2'b10 && primo == 2'b01 ||
                         secondo == 2'b11 && primo == 2'b10) begin
                  		 manche = 2'b10;
                  	     partita = 2'b00;
                  		 
                       if(vantaggio_mag_1_2) begin
                         stato_prossimo = stato; // se sono ancora in vantaggio, resto nello stesso stato
                       end else begin
                         stato_prossimo = 3'b011; // se vantaggio = 1 e vince 2, pareggio
                       end
                    end else if(primo == 2'b00 || secondo == 2'b00) begin
                        manche = 2'b00;
                        partita = 2'b00;
                        stato_prossimo = 3'b001;
                    end else begin
                        manche = 2'b11;
                        partita = 2'b00;
                        stato_prossimo = 3'b001;
                    end
                end else begin
                  manche = 2'b00;
                  partita = 2'b00;
                  stato_prossimo = 3'b001;
                end
              end


            3'b010: // stato di vantaggio del giocatore 2
              if(inizia) begin
                manche = 2'b00;
                partita = 2'b00;
                stato_prossimo = 3'b000;
              end else if(forza_fine || (terminabile && vantaggio_mag_2_2)) begin
                manche = vincitore_prec;
                partita = 2'b10;
                stato_prossimo = 3'b100;
              end else begin
                if(mosse_valide) begin
                   if(primo == 2'b01 && secondo == 2'b11 || 
                   		primo == 2'b10 && secondo == 2'b01 || 
                   		primo == 2'b11 && secondo == 2'b10) begin
                    	manche = 2'b01;           // manche vinta dal primo giocatore
                    	partita = 2'b00;         // partita non ancora terminata
                     
                     if(vantaggio_mag_2_2) begin
                       stato_prossimo = stato; // se vant >= 2, resto nello stesso
                     end else begin
                       stato_prossimo <= 3'b011; // se vant = 1, pareggio
                     end
                	end else if(secondo == 2'b01 && primo == 2'b11 || 
                        secondo == 2'b10 && primo == 2'b01 || 
                        secondo == 2'b11 && primo == 2'b10) begin
                    	manche <= 2'b10;          // manche vinta dal giocatore 2
                   	 	partita <= 2'b00;         // partita non ancora terminata
                    	stato_prossimo <= 3'b010; // passo allo stato di vantaggio di 2 del giocatore 2
                	end else if(primo == 2'b00 || secondo == 2'b00) begin
                    	manche <= 2'b00;        // manche non valida
                    	partita <= 2'b00;       // partita non terminata
                    	stato_prossimo <= 3'b010; 
                	end else begin
                    	manche <= 2'b11;         // manche pareggiata
                    	partita <= 2'b00;        // partita non ancora terminata
                    	stato_prossimo <= 3'b010; // passaggio allo stato di pareggio
                	end
                end else begin
                  manche = 2'b00;
                  partita = 2'b00;
                  stato_prossimo = 3'b010;
                end
              end
            

            3'b011: // stato di pareggio di punteggi
              if(inizia) begin
              end else if(forza_fine) begin
                partita = 2'b11;
                stato_prossimo = 3'b100;
              end else begin
                if(mosse_valide) begin
                   if(primo == 2'b01 && secondo == 2'b11 || 
                   		primo == 2'b10 && secondo == 2'b01 || 
                   		primo == 2'b11 && secondo == 2'b10) begin
                    	manche = 2'b01;             // manche vinta dal primo giocatore
                    	partita = 2'b00;            // partita non ancora terminata
                    	stato_prossimo = 3'b001;    // passo allo stato dove il giocatore 1 è in vantaggio di 1
                	end else if(secondo == 2'b01 && primo == 2'b11 || 
                        secondo == 2'b10 && primo == 2'b01 || 
                        secondo == 2'b11 && primo == 2'b10) begin
                    	manche = 2'b10;            // manche vinta dal giocatore 2
                    	partita = 2'b00;           // partita non ancora terminata
                    	stato_prossimo = 3'b010;   // passo allo stato di vantaggio di 1 del giocatore 2
                	end else if(primo == 2'b00 || secondo == 2'b00) begin
                    	manche = 2'b00;
                    	partita = 2'b00;         // uscita
                    	stato_prossimo = 3'b011;
                	end else begin
                    	manche = 2'b11;          // manche pareggiata
                    	partita = 2'b00;         // partita non ancora terminata
                    	stato_prossimo = 3'b011; // passaggio allo stato di pareggio
                	end
                end else begin
                  manche = 2'b00;
                  partita = 2'b00;
                  stato_prossimo = 3'b011;
                end
              end
               
            3'b100: // stato di fine
              	stato_prossimo = 3'b100;
        endcase
    end

  always @(manche) begin : DATAPATH_USCITE
        vincitore_prec = manche; // valorizzo il vincitore precedente
    
    	// valorizzo la mossa precedente
        case (manche)
          	2'b00,2'b11:
                 mossa_prec = 2'b00;
            2'b01:
          		mossa_prec = primo;
            2'b10:
          		mossa_prec = secondo;
        endcase
      
      	// case per aumentare i contatori
        case(manche)
          2'b01:
            count1 = count1 + 1;
          2'b10:
            count2 = count2 + 1;
        endcase
    
    	// incremento il valore di count manche
    	case(manche)
      		2'b01, 2'b10, 2'b11:
        	count_manche = count_manche + 1;
    	endcase
    end
endmodule