module tb();
  	reg [3:0] in;
  	wire [3:0] out;
	
	integer i;
	
	complemento c(.in(in), .out(out));

	initial begin 
        $dumpfile("dump.vcd");
        $dumpvars(1);
        for(i=-7; i<= 7;i=i+1)begin
            in <= i;
            #2;
            $display ("in: %d -> out: %d",
                $signed(in), $signed(out));
        end
    end

endmodule
