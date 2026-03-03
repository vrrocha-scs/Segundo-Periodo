
module codificador_tb;

    //definição do periodo do clk 
    parameter CLK_PERIOD = 10;

    logic        clk;
    logic        rst;
    logic        start;
    logic [7:0]  key;
    logic [7:0]  plaintext;
    logic [7:0]  ciphertext;
    logic        done;
  
    codificador dut (
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
        plaintext = 8'b0;
        
        // Aplica um pulso de reset no início
        rst = 1;
        repeat (2) @(posedge clk); // Espera 2 ciclos de clock
        rst = 0;
        
        // Espera um pouco mais para estabilizar
        repeat (2) @(posedge clk);

        //TESTE 1
        key       = 8'b10100101;
        plaintext = 8'b11110000; 
        $display("Teste 1");
        $display("XOR : %08b ^ %08b",key,plaintext);
        
        //pulso start de um ciclo de clk de duração
        start = 1;
        @(posedge clk);
        start = 0;
       
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
        if(key^plaintext==ciphertext) $display("teste 1 ocorreu com sucesso");
                
        //Espera para o teste 2
        repeat (5) @(posedge clk);

        //TESTE 2
        key       = 8'b11111111;
        plaintext = 8'b11111111;
        $display("Teste 2");
        $display("XOR : %08b ^ %08b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
        if(key^plaintext==ciphertext) $display("teste 2 ocorreu com sucesso");

      
      //Espera para o teste 3
        repeat (5) @(posedge clk);

        //TESTE 3
        key       = 8'b10111101;
        plaintext = 8'b10101011;
        $display("Teste 3");
        $display("XOR : %08b ^ %08b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
        if(key^plaintext==ciphertext) $display("teste 3 ocorreu com sucesso");

      
      //Espera para o teste 4
        repeat (5) @(posedge clk);
      
      //TESTE 4
        key       = 8'b11011011;
        plaintext = 8'b11110011;
        $display("Teste 4");
        $display("XOR : %08b ^ %08b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
        if(key^plaintext==ciphertext) $display("teste 4 ocorreu com sucesso");

      //Espera para o teste 5
        repeat (5) @(posedge clk);
      
      //TESTE 5
        key       = 8'b10101010;
        plaintext = 8'b11100011;
        $display("Teste 5");
        $display("XOR : %08b ^ %08b",key,plaintext);  
      
        start = 1;
        @(posedge clk);
        start = 0;
        
        @(posedge done);
        $display("Sinal done recebido");
        $display("resultado da  cifra : %08b",ciphertext);
      if(key^plaintext==ciphertext) $display("teste 5       ocorreu com sucesso");

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