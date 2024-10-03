module sd(
    input [3:0] n1,
    input [3:0] n2,
    input [0:0] check,
    output reg [3:0] out
);

/*
Scrivere un componente che riceve in ingresso due numeri a 4 bit ed un
segnale di controllo. Se il segnale di controllo vale ’0’ il componente
effettuerà la somma dei due numeri in ingresso; altrimenti, eseguirá la
sottrazione. Utilizzare lo stile comportamentale per descrivere il circuito.
*/

    always @(n1 or n2) begin
        if(check==0) begin
            out = n1+n2;
        end
        else begin
            out = n1-n2;
        end
    end

endmodule