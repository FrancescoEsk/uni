module design2(
    input clk, // clock
    input reg [1:0] primo,
    input reg [1:0] secondo,
    input inizio, 
    
    output reg [1:0] manche,
);
    reg STATO_PROSSIMO[2:0];

    reg MOSSA_PRECEDENTE[1:0];
    reg VINCITORE_PRECEDENTE[1:0];
    reg COUNT[4:0];
    reg MAX[4:0];

    reg OUTPUT_MANCHE[1:0];

    bit NO_VALID;
    bit COUNT_MIN;
    bit COUNT_MAX;

    always @(posedge clk) begin // INIZIO / RESET
        if (inizio) begin
            // contare partite massime da giocare - parentesi graffe concatenano (10 01 --> 1001)
            max = 5'b00100 + {primo, secondo};
            // 10 11 -> 1011

            count = 5'b00000;
            // ...

            stato_prossimo = 3'b000; // bit di stato iniziale 
        end else begin
            stato = stato_prossimo; // se non ho reset, aggiorno lo stato
        end
    end

    always @(primo, secondo) begin : DATAPATH
        if (primo == 2'b10 && secondo == 2'b01
        || primo == 2'b01 && secondo == 2'b11
        || primo == 2'b11 && secondo == 2'b10) begin
                // VINCE 1
                OUTPUT_MANCHE = 2'b10;
            end else begin
                OUTPUT_MANCHE = 2'b01;
            end
        if (primo == secondo)
            OUTPUT_MANCHE = 2'b11;

        if (nnsns)
            OUTPUT_MANCHE = 2'b00;

        
        if (OUTPUT_MANCHE == 2'b00)
            NO_VALID = 1'b1;
        else
            NO'VALID = 1'b0;

        case(OUTPUT_MANCHE) 
            2'b01: begin
                MOSSA_PRECEDENTE = secondo;
            end

            2'b10: begin
                MOSSA_PRECEDENTE = ;
            end

            2'b11: begin
                MOSSA_PRECEDENTE = ;
            end
        endcase
    end



endmodule