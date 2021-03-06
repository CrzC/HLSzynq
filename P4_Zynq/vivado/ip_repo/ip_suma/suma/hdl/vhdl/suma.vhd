-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity suma is
generic (
    C_S_AXI_BUS_A_ADDR_WIDTH : INTEGER := 6;
    C_S_AXI_BUS_A_DATA_WIDTH : INTEGER := 32 );
port (
    ap_clk : IN STD_LOGIC;
    ap_rst_n : IN STD_LOGIC;
    s_axi_BUS_A_AWVALID : IN STD_LOGIC;
    s_axi_BUS_A_AWREADY : OUT STD_LOGIC;
    s_axi_BUS_A_AWADDR : IN STD_LOGIC_VECTOR (C_S_AXI_BUS_A_ADDR_WIDTH-1 downto 0);
    s_axi_BUS_A_WVALID : IN STD_LOGIC;
    s_axi_BUS_A_WREADY : OUT STD_LOGIC;
    s_axi_BUS_A_WDATA : IN STD_LOGIC_VECTOR (C_S_AXI_BUS_A_DATA_WIDTH-1 downto 0);
    s_axi_BUS_A_WSTRB : IN STD_LOGIC_VECTOR (C_S_AXI_BUS_A_DATA_WIDTH/8-1 downto 0);
    s_axi_BUS_A_ARVALID : IN STD_LOGIC;
    s_axi_BUS_A_ARREADY : OUT STD_LOGIC;
    s_axi_BUS_A_ARADDR : IN STD_LOGIC_VECTOR (C_S_AXI_BUS_A_ADDR_WIDTH-1 downto 0);
    s_axi_BUS_A_RVALID : OUT STD_LOGIC;
    s_axi_BUS_A_RREADY : IN STD_LOGIC;
    s_axi_BUS_A_RDATA : OUT STD_LOGIC_VECTOR (C_S_AXI_BUS_A_DATA_WIDTH-1 downto 0);
    s_axi_BUS_A_RRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
    s_axi_BUS_A_BVALID : OUT STD_LOGIC;
    s_axi_BUS_A_BREADY : IN STD_LOGIC;
    s_axi_BUS_A_BRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
    interrupt : OUT STD_LOGIC );
end;


architecture behav of suma is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "suma,hls_ip_2019_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020-clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.256000,HLS_SYN_LAT=9,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=2,HLS_SYN_FF=467,HLS_SYN_LUT=766,HLS_VERSION=2019_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (9 downto 0) := "0000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (9 downto 0) := "0000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (9 downto 0) := "0000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (9 downto 0) := "0000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (9 downto 0) := "0000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (9 downto 0) := "0001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (9 downto 0) := "0010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (9 downto 0) := "0100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (9 downto 0) := "1000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant C_S_AXI_DATA_WIDTH : INTEGER range 63 downto 0 := 20;
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_rst_n_inv : STD_LOGIC;
    signal ap_start : STD_LOGIC;
    signal ap_done : STD_LOGIC;
    signal ap_idle : STD_LOGIC;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (9 downto 0) := "0000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal ap_ready : STD_LOGIC;
    signal a : STD_LOGIC_VECTOR (31 downto 0);
    signal b : STD_LOGIC_VECTOR (31 downto 0);
    signal c_i : STD_LOGIC_VECTOR (31 downto 0);
    signal c_o_ap_vld : STD_LOGIC;
    signal c_read_reg_68 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_51_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_reg_73 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal ap_CS_fsm_state10 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state10 : signal is "none";
    signal grp_fu_51_p0 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_51_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal ap_NS_fsm : STD_LOGIC_VECTOR (9 downto 0);

    component suma_fadd_32ns_32bkb IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component suma_BUS_A_s_axi IS
    generic (
        C_S_AXI_ADDR_WIDTH : INTEGER;
        C_S_AXI_DATA_WIDTH : INTEGER );
    port (
        AWVALID : IN STD_LOGIC;
        AWREADY : OUT STD_LOGIC;
        AWADDR : IN STD_LOGIC_VECTOR (C_S_AXI_ADDR_WIDTH-1 downto 0);
        WVALID : IN STD_LOGIC;
        WREADY : OUT STD_LOGIC;
        WDATA : IN STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH-1 downto 0);
        WSTRB : IN STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH/8-1 downto 0);
        ARVALID : IN STD_LOGIC;
        ARREADY : OUT STD_LOGIC;
        ARADDR : IN STD_LOGIC_VECTOR (C_S_AXI_ADDR_WIDTH-1 downto 0);
        RVALID : OUT STD_LOGIC;
        RREADY : IN STD_LOGIC;
        RDATA : OUT STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH-1 downto 0);
        RRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
        BVALID : OUT STD_LOGIC;
        BREADY : IN STD_LOGIC;
        BRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
        ACLK : IN STD_LOGIC;
        ARESET : IN STD_LOGIC;
        ACLK_EN : IN STD_LOGIC;
        ap_start : OUT STD_LOGIC;
        interrupt : OUT STD_LOGIC;
        ap_ready : IN STD_LOGIC;
        ap_done : IN STD_LOGIC;
        ap_idle : IN STD_LOGIC;
        a : OUT STD_LOGIC_VECTOR (31 downto 0);
        b : OUT STD_LOGIC_VECTOR (31 downto 0);
        c_o : IN STD_LOGIC_VECTOR (31 downto 0);
        c_o_ap_vld : IN STD_LOGIC;
        c_i : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    suma_BUS_A_s_axi_U : component suma_BUS_A_s_axi
    generic map (
        C_S_AXI_ADDR_WIDTH => C_S_AXI_BUS_A_ADDR_WIDTH,
        C_S_AXI_DATA_WIDTH => C_S_AXI_BUS_A_DATA_WIDTH)
    port map (
        AWVALID => s_axi_BUS_A_AWVALID,
        AWREADY => s_axi_BUS_A_AWREADY,
        AWADDR => s_axi_BUS_A_AWADDR,
        WVALID => s_axi_BUS_A_WVALID,
        WREADY => s_axi_BUS_A_WREADY,
        WDATA => s_axi_BUS_A_WDATA,
        WSTRB => s_axi_BUS_A_WSTRB,
        ARVALID => s_axi_BUS_A_ARVALID,
        ARREADY => s_axi_BUS_A_ARREADY,
        ARADDR => s_axi_BUS_A_ARADDR,
        RVALID => s_axi_BUS_A_RVALID,
        RREADY => s_axi_BUS_A_RREADY,
        RDATA => s_axi_BUS_A_RDATA,
        RRESP => s_axi_BUS_A_RRESP,
        BVALID => s_axi_BUS_A_BVALID,
        BREADY => s_axi_BUS_A_BREADY,
        BRESP => s_axi_BUS_A_BRESP,
        ACLK => ap_clk,
        ARESET => ap_rst_n_inv,
        ACLK_EN => ap_const_logic_1,
        ap_start => ap_start,
        interrupt => interrupt,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_idle => ap_idle,
        a => a,
        b => b,
        c_o => grp_fu_51_p2,
        c_o_ap_vld => c_o_ap_vld,
        c_i => c_i);

    suma_fadd_32ns_32bkb_U1 : component suma_fadd_32ns_32bkb
    generic map (
        ID => 1,
        NUM_STAGE => 5,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst_n_inv,
        din0 => grp_fu_51_p0,
        din1 => grp_fu_51_p1,
        ce => ap_const_logic_1,
        dout => grp_fu_51_p2);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst_n_inv = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;

    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                c_read_reg_68 <= c_i;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state5)) then
                tmp_reg_73 <= grp_fu_51_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state10;
            when ap_ST_fsm_state10 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state10 <= ap_CS_fsm(9);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);

    ap_done_assign_proc : process(ap_CS_fsm_state10)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state10)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;


    ap_rst_n_inv_assign_proc : process(ap_rst_n)
    begin
                ap_rst_n_inv <= not(ap_rst_n);
    end process;


    c_o_ap_vld_assign_proc : process(ap_CS_fsm_state10)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state10)) then 
            c_o_ap_vld <= ap_const_logic_1;
        else 
            c_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;


    grp_fu_51_p0_assign_proc : process(ap_CS_fsm_state1, a, c_read_reg_68, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            grp_fu_51_p0 <= c_read_reg_68;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state1)) then 
            grp_fu_51_p0 <= a;
        else 
            grp_fu_51_p0 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end if; 
    end process;


    grp_fu_51_p1_assign_proc : process(ap_CS_fsm_state1, b, tmp_reg_73, ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            grp_fu_51_p1 <= tmp_reg_73;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state1)) then 
            grp_fu_51_p1 <= b;
        else 
            grp_fu_51_p1 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end if; 
    end process;

end behav;
