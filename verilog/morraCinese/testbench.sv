module tb();

    reg [1:0] i1;
    reg [1:0] i2;
    reg [0:0] inizio;
    reg clk;
    wire [1:0] manche;
    wire [1:0] partita;
    wire [2:0] stato;

    integer i, z, tbf, outf;

    always #5 clk = ~clk; // switch clock ogni 5 nano secondi

    MorraCinese m(clk, i1, i2, inizio, manche, partita, stato);

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(1);
        tbf = $fopen("testbench.script", "w");
        outf = $fopen("output_verilog.txt", "w");
        clk = 1'b0; // start clock

        inizio = 1'b1; // imposto come max partite 6 resettando la macchina
        i1 = 2'b00;
        i2 = 2'b10;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        #20;
        inizio = 1'b0;
        // partita 1, vince 2
        i1 = 2'b01;
        i2 = 2'b10;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        // partita 2, vince 2
        i1 = 2'b10;
        i2 = 2'b11;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        // partita 3, vince 1
        i1 = 2'b10;
        i2 = 2'b01;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        // partita 4, pareggio
        i1 = 2'b11;
        i2 = 2'b11;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        // partita 5, vince 1
        i1 = 2'b10;
        i2 = 2'b01;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);
        // partita 6, vince 1
        i1 = 2'b11;
        i2 = 2'b10;
        #20;
        $display(tbf, "simulate %b %b", i1, i2, inizio);
        $display(outf, "in: %b %b %b --> Outputs: %b %b %b", i1, i2, inizio, manche, partita, stato);

        $display(tbf, "quit");
        $fclose(tbf);
        $fclose(outf);
        $finish;
    end

endmodule