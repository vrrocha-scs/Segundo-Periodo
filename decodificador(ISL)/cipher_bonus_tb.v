
module codificador_tb;

    //definição do periodo do clk 
    parameter CLK_PERIOD = 10;

    logic        clk;
    logic        rst;
    logic        start;
    logic [7:0]  key;
    logic [31:0]  plaintext;
    logic [31:0]  ciphertext;
    logic        done;
  
    codificador_bonus dut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .key(key),
        .plaintext(plaintext),
        .ciphertext(ciphertext),
        .done(done)
    );
     

    // inverte o sinal do clk a cada meio periodo de clk
    initial begin
        clk = 0;
        forever #(CLK_PERIOD / 2) clk = ~clk;
    end

    // testes
    initial begin
        start = 0;
        key = 8'b0;
        plaintext = 32'b0;
        
        // Aplica um pulso de reset no início
        rst = 1;
        repeat (2) @(posedge clk); // Espera 2 ciclos de clock
        rst = 0;
        
        // Espera um pouco mais para estabilizar
        repeat (2) @(posedge clk);

        //TESTE 1
        key       = 8'hA5;
        plaintext = 32'hFFFFFFFF; 
        $display("Teste 1");
        $display("XOR : %08b ^ %32b",key,plaintext);
        
        //pulso start de um ciclo de clk de duração
        start = 1;
        @(posedge clk);
        start = 0;
       
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %32b",ciphertext);
        if (ciphertext == 32'b10101011010101101010110101011010) $display("teste 1 ocorreu com sucesso");
        else $display("erro no teste 1");                
        //Espera para o teste 2
        repeat (5) @(posedge clk);

        //TESTE 2
        key       = 8'b11001100;
        plaintext = 32'hFF00AAF0;
        $display("Teste 2");
        $display("XOR : %08b ^ %32b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
if (ciphertext == 32'b00111001011100111011001100111100) $display("teste 2 ocorreu com sucesso");
        else $display("erro no teste 2"); 
      //Espera para o teste 3
        repeat (5) @(posedge clk);

        //TESTE 3
        key= 8'b11001010;
        plaintext = 32'hB8F0F0F;
        $display("Teste 3");
        $display("XOR : %08b ^ %08b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
        if (ciphertext == 32'b10100001111111011010011011000101) $display("teste 3 ocorreu com sucesso");
        else $display("erro no teste 3");     
        //fim do teste
      $display("Fim dos testes");
        $finish;
    end

  //geração de arquivos de onda
  initial begin
    $dumpfile("ondas.vcd");
    $dumpvars(0, codificador_tb);
  end
endmodule