module tb();

    reg [3:0] x;
    reg [3:0] y;
    wire [3:0] o;

    integer i;

    somma2bit s(.a(x), .b(y), .out(o));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(1);

        for(i=1; i<10; i++) begin
            x <= i-1;
            y <= i;
            #2;
            $display("in: %d %d --> out: %d", x, y, o);
        end
    end

endmodule