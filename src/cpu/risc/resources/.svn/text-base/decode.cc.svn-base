/**
 * Copyright (C) Tsinghua University 2013
 * 
 * Version : 1.0
 * Date    : 20 April 2013
 * Author  : Li Xiaotian
 * Company : Tsinghua University
 * Email   : lixtmail@163.com
 */
 
#include "decode.hh"
#include "cpu/risc/isa/categories/includes.hh"

namespace LILY2_NS
{
	
Decode::Decode(RiscCPU *cpu)
    : Resource(cpu)
{
}

Decode::~Decode(void)
{
}

StaticInst *
Decode::decode_inst(ExtMachInst mach_inst)
{
	_mach_inst = mach_inst;
	
	switch(INST_LEN) {
		case 0x0: {
			switch(OP_1_B) {
				case 0x00: {
					switch(OP_2_B) {
						case 0x0: {
							switch(OP_3_B) {
								case 0x0: { return new EOC(mach_inst); }
								
								default: { return new UNKNOWN(mach_inst); }
							}
						}
						
						default: { return new UNKNOWN(mach_inst); }
					}
				}
				
				default: { return new UNKNOWN(mach_inst); }
			}
		}
		
		case 0x2: {
			switch(OP_1_B) {
				case 0x1e: {
					switch(OP_2_B) {
						case 0x7: {
							switch(OP_3_B) {
								case 0x00: { return new RET16_D(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						default: { return new UNKNOWN(mach_inst); }
					}
				}
				
				default: { return new UNKNOWN(mach_inst); }
			}
		}
		
		case 0x3: {
			switch(UNIT_SEL) {
				case 0x0: {
					switch(OP_1) {
						case 0x0: {
							switch(OP_2) {
								case 0x00: { return new ADD_A(mach_inst); }
								case 0x03: { return new ADDI_A(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst);}
							}
						}
						
						case 0x1: {
							switch(OP_2) {
								case 0x00: { return new SUB_A(mach_inst); }
								case 0x03: { return new SUBI_A(mach_inst); }
								
								case 0x1c: { return new EXT_A(mach_inst); }
								case 0x1d: { return new EXTU_A(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x2: {
							switch(OP_2) {
								case 0x00: { return new ASL_A(mach_inst); }
								case 0x01: { return new ASLI_A(mach_inst); }
								
								case 0x04: { return new ASR_A(mach_inst); }
								case 0x05: { return new ASRI_A(mach_inst); }
								
								case 0x08: { return new LSR_A(mach_inst); }
								case 0x09: { return new LSRI_A(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x3: {
							switch(OP_2) {
								case 0x0c: { return new AND_A(mach_inst);   }
								case 0x0d: { return new ANDI_A(mach_inst);  }
								case 0x0e: { return new NAND_A(mach_inst);  }
								case 0x0f: { return new NANDI_A(mach_inst); }
								case 0x10: { return new OR_A(mach_inst);    }
								case 0x11: { return new ORI_A(mach_inst);   }
								case 0x12: { return new NOR_A(mach_inst);   }
								case 0x13: { return new NORI_A(mach_inst);  }
								case 0x14: { return new XOR_A(mach_inst);   } 
								case 0x15: { return new XORI_A(mach_inst);  }
								case 0x16: { return new XNOR_A(mach_inst);  }
								case 0x17: { return new XNORI_A(mach_inst); }
								
								case 0x1c: { return new MAX_A(mach_inst);   }
								case 0x1d: { return new MIN_A(mach_inst);   }
								
								case 0x1f: {
									switch(OP_3) {
										case 0x00: { return new ABS_A(mach_inst);   }
										
										case 0x08: { return new NEG_A(mach_inst);   }
										
										case 0x0e: { return new NOT_A(mach_inst);   }
										
										default:   { return new UNKNOWN(mach_inst); }
									}
								}
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x4:
						case 0x5: { return new ADDK_A(mach_inst); }
						case 0x6: {
							switch(OP_2) {
								case 0x0d: { return new ANDN_A(mach_inst);  }
								case 0x0e: { return new ORN_A(mach_inst);   }
								case 0x0f: { return new SELB_A(mach_inst);  }
								
								case 0x12: { return new PUTB_A(mach_inst);  }
								case 0x13: { return new XORN_A(mach_inst);  }
								case 0x14: { return new XOR3_A(mach_inst);  }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						default:  return new UNKNOWN(mach_inst);
					}
				}
				
				case 0x1: {
					switch(OP_1) {
						case 0x0: {
							switch(OP_2) {
								case 0x05: { return new MULSL_M(mach_inst); }
								
								default: { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x2: {
							switch(OP_2) {
								case 0x0c: { return new DIV_M(mach_inst);  }
								case 0x0d: { return new DIVU_M(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x3: {
							switch(OP_2) {
								case 0x1f: {
									switch(OP_3) {
										case 0x09: { return new MOVR_M(mach_inst); }
										case 0x0b: { return new SXT1_M(mach_inst); }
										case 0x0c: { return new ZXT1_M(mach_inst); }
										case 0x0d: { return new SXT2_M(mach_inst); }
										case 0x0e: { return new ZXT2_M(mach_inst); }
										
										default: { return new UNKNOWN(mach_inst); }
									}
								}
								
								default: { return new UNKNOWN(mach_inst); }
							}
						}
						case 0x4:
						case 0x5: { return new MOVK_M(mach_inst); }
						case 0x6:
						case 0x7: { return new MOVKH_M(mach_inst); }
						
						default: return new UNKNOWN(mach_inst);
					}
				}
				
				case 0x2: {
					switch(OP_1) {
						case 0x0: {
							switch(OP_2) {
								case 0x00: { return new CMPGT_D(mach_inst); }
								case 0x01: { return new CMPGTI_D(mach_inst); }
								case 0x04: { return new CMPGTU_D(mach_inst); }
								case 0x05: { return new CMPGTUI_D(mach_inst); }
								case 0x08: { return new CMPLT_D(mach_inst); }
								case 0x09: { return new CMPLTI_D(mach_inst); }
								case 0x0c: { return new CMPLTU_D(mach_inst); }
								case 0x0d: { return new CMPLTUI_D(mach_inst); }
								case 0x10: { return new CMPEQ_D(mach_inst); }
								case 0x11: { return new CMPEQI_D(mach_inst); }
								
								case 0x1f: {
									switch(OP_3) {
										case 0x08: { return new BR_D(mach_inst);    }
										case 0x0a: { return new CALLR_D(mach_inst); }
										case 0x1e: { return new SETR_D(mach_inst);  }
										
										default:   { return new UNKNOWN(mach_inst); }
									}
								}
								
								default: return new UNKNOWN(mach_inst);
							}
						}
						
						case 0x1: {
							switch(OP_2) {
								case 0x8: {
									switch(OP_3) {
										case 0x10: { return new MOVRC_D(mach_inst); }
										
										default: { return new UNKNOWN(mach_inst); }
									}
								}
								
								default: return new UNKNOWN(mach_inst);
							}
						}
						
						default: return new UNKNOWN(mach_inst);
					}
				}
				
				case 0x3: {
					switch(OP_1) {
						case 0x0: { return new B_D(mach_inst); }
						case 0x2: { return new CALL_D(mach_inst); }
						case 0x3: {
							switch(OP_2) {
								case 0x00: { return new STW_NO_OFFSET_D(mach_inst); }
								case 0x02:
								case 0x03: { return new STW_D(mach_inst); }
								
								case 0x08:
								case 0x09:
								case 0x0a:
								case 0x0b: { return new STWI_D(mach_inst); }
								
								default:  { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x4: {
							switch(OP_2) {
								case 0x00: { return new LDB_NO_OFFSET_D(mach_inst); }
								case 0x02:
								case 0x03: { return new LDB_D(mach_inst); }
								
								case 0x08:
								case 0x09:
								case 0x0a:
								case 0x0b: { return new LDBI_D(mach_inst); }
								
								case 0x10: { return new LDBU_NO_OFFSET_D(mach_inst); }
								case 0x12:
								case 0x13: { return new LDBU_D(mach_inst); }
								
								case 0x18:
								case 0x19:
								case 0x1a:
								case 0x1b: { return new LDBUI_D(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x5: {
							switch(OP_2) {
								case 0x00: { return new LDH_NO_OFFSET_D(mach_inst); }
								case 0x02:
								case 0x03: { return new LDH_D(mach_inst); }
								
								case 0x08:
								case 0x09:
								case 0x0a:
								case 0x0b: { return new LDHI_D(mach_inst); }
								
								case 0x10: { return new LDHU_NO_OFFSET_D(mach_inst); }
								case 0x12:
								case 0x13: { return new LDHU_D(mach_inst); }
								
								case 0x18:
								case 0x19:
								case 0x1a:
								case 0x1b: { return new LDHUI_D(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x6: {
							switch(OP_2) {
								case 0x00: { return new LDW_NO_OFFSET_D(mach_inst); }
								case 0x02:
								case 0x03: { return new LDW_D(mach_inst); }
								
								case 0x08:
								case 0x09:
								case 0x0a:
								case 0x0b: { return new LDWI_D(mach_inst); }
								
								default:  { return new UNKNOWN(mach_inst); }
							}
						}
						
						case 0x7: {
							switch(OP_2) {
								case 0x00: { return new STB_NO_OFFSET_D(mach_inst); }
								case 0x02:
								case 0x03: { return new STB_D(mach_inst); }
								
								case 0x08:
								case 0x09:
								case 0x0a:
								case 0x0b: { return new STBI_D(mach_inst); }
								
								case 0x10: { return new STH_NO_OFFSET_D(mach_inst); }
								case 0x12:
								case 0x13: { return new STH_D(mach_inst); }
								
								case 0x18:
								case 0x19:
								case 0x1a:
								case 0x1b: { return new STHI_D(mach_inst); }
								
								default:   { return new UNKNOWN(mach_inst); }
							}
						}
						
						default: { return new UNKNOWN(mach_inst); }
					}
				}
			}
		}
		
		default:  return new UNKNOWN(mach_inst);
	}
}
	
} // LILY2_NS
