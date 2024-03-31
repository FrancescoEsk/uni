module tb();

    reg [3:0] a;
    reg [3:0] b;
    reg [0:0] x;
    wire [3:0] o;

    integer i;

    sd c(.n1(a), .n2(b), .check(x), .out(o));

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(1);

        for (i=1; i<10; i++) begin
            if (i%2 == 0)   x=1;
            else    x=0;
            a <= i;
            b <= i-1;
            #2;
            $display("in: %d %d c: %d --> out: %d", a, b, x, o);
        end
    end

endmodule