module somma2bit(
    input [3:0] a, // variabile 4 bit
    input [3:0] b,
    output reg [3:0] out // reg output 4 bit
);

/*
Scrivere il testbench per il sommatore a quattro bit (esempio 2), descritto
con lo stile comportamentale. Utilizzare i costrutti iterativi (for oppure
while) per testare tutte le possibili combinazioni di ingresso
*/
    
    always @(a or b)begin
        out = a+b;
    end

    /*
    always @(!a or !b)begin
        out = 4'b0000;
    end
    */

endmodule 