module complemento(input [3:0] in, output [3:0] out);

    integer i;
    reg [3:0] negato;

    always @(in)
    begin
        for (i=0; i<4; i = i+1)begin
            negato[i] <= !in[i];
        end
    end

    assign out = negato + 1;
endmodule
