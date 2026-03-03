module codificador(input logic clk,
                  input logic rst,
                  input logic start,
                  input logic [7:0] key,
                  input logic [7:0] plaintext,
                   output logic [7:0] ciphertext,
                   output logic done);
  
  typedef enum logic [1:0]{IDLE,
                           LOAD,
                           PROCESS,
                           DONE} statetype;
  
  statetype state_actual, state_next;
  logic [3:0] counter;
  logic [7:0] key_aux;
  logic [7:0] plaintext_aux;
  logic [7:0] ciphertext_aux;
  logic counter_7;
  
 //bloco sequencial 
  always_ff @(posedge clk) begin
    if(rst) begin
      state_actual <= IDLE;
      counter <= 4'b0;
      ciphertext_aux <= 8'b0;   
      key_aux<=8'b0;
      plaintext_aux<=8'b0;
    end else begin
      state_actual <=state_next;  
    case(state_actual)
      LOAD : begin
        key_aux<=key;
        plaintext_aux<=plaintext;
        counter<=4'b0;
       end
      
      PROCESS : begin
        ciphertext_aux[counter]<=key_aux[counter]^plaintext_aux[counter];
         counter<=counter+1;
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
        if(counter_7) state_next=DONE;
      end
      DONE:begin
        done=1'b1;
        state_next=IDLE;
      end
     endcase
   end
  assign counter_7 = (counter == 4'd7);
  
  assign ciphertext=ciphertext_aux;
  
endmodule