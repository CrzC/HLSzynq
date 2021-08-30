library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity gates_mux is
   Port ( a : in STD_LOGIC;  
           b : in STD_LOGIC;  
           c : out STD_LOGIC;  
           sel : in STD_LOGIC_VECTOR (1 downto 0)); 
end gates_mux;

architecture Behavioral of gates_mux is

begin
mux_compuertas : process(a,b,sel)  
begin  
  case sel is  
    when "00" => c <= a and b;  
    when "01" => c <= a or b ;  
    when "10" => c <= a xor b;  
    when others => c <= a nor b ;  
  end case;  
end process mux_compuertas;  

end Behavioral;
