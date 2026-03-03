module codificador_bonus(input logic clk,
                  input logic rst,
                  input logic start,
                  input logic [7:0] key,
                  input logic [31:0] plaintext,
                   output logic [31:0] ciphertext,
                   output logic done);
  
  typedef enum logic [1:0]{IDLE,
                           LOAD,
                           PROCESS,
                           DONE} statetype;
  
  statetype state_actual, state_next;
  logic [7:0] key_aux;
  logic [31:0] plaintext_aux;
  logic [31:0] ciphertext_aux;
  //sinais para o contador
  logic [5:0] process_counter;
  logic [2:0] key_index;
  logic direcionador; //indica a direcao do contador(aumentando=1;diminuindo=0)
  logic verificador;

 //bloco sequencial 
  always_ff @(posedge clk) begin
    if(rst) begin
      state_actual <= IDLE;
      process_counter<= '0;
      key_index<='0;
      direcionador<=1'b1;
      ciphertext_aux <= '0;   
      key_aux<='0;
      plaintext_aux<='0;
    end else begin
      state_actual <=state_next;  

    case(state_actual)
      LOAD : begin
        key_aux<=key;
        plaintext_aux<=plaintext;
        process_counter<='0;
        key_index<='0;
        direcionador<=1'b1;
        ciphertext_aux<='0;
       end
      
      PROCESS : begin
        ciphertext_aux[process_counter]<=plaintext_aux[process_counter]^key_aux[key_index];
        process_counter<=process_counter+1;

        if(direcionador)begin
            if(key_index==7)begin //verifica se chegou no fim da chave
                direcionador<=1'b0;//inverte a direcao
                key_index<=key_index-1;
            end else begin
                key_index<=key_index+1;
            end
        end else begin
            if(key_index==0) begin
              direcionador<=1'b1;//inverte a direcao 
              key_index<=key_index+1;
            end else begin
              key_index<=key_index-1;
            end
        end 
       end
    endcase
  end
 end
  
  //bloco combinacional
  always_comb begin
    state_next= state_actual;
    done=1'b0;
    
    case(state_actual)
      IDLE:begin
        if(start) begin
          state_next=LOAD;
        end
      end
      LOAD:begin
        state_next=PROCESS;
      end
      PROCESS:begin
        if(verificador) state_next=DONE;
      end
      DONE:begin
        done=1'b1;
        state_next=IDLE;
      end
     endcase
   end
  assign verificador = (process_counter ==32);
  
  assign ciphertext=ciphertext_aux;
  
endmodule