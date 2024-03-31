module tb();
    reg [0:0] a;
    reg [0:0] b;
    wire [0:0] o;

    integer i;

    somma s(.n1(a), .n2(b), .out(o));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(1);

        a <= 0;
        b <= 1;
        #2;
        $display("in: %d %d --> out: %d", a, b, o);

        a <= 0;
        b <= 0;
        #2;
        $display("in: %d %d --> out: %d", a, b, o);

        a <= 1;
        b <= 0;
        #2;
        $display("in: %d %d --> out: %d", a, b, o);

        a <= 1;
        b <= 1;
        #2;
        $display("in: %d %d --> out: %d", a, b, o);
    end
endmodule