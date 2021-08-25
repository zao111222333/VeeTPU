// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdderTree16.h for the primary calling header

#include "VAdderTree16.h"
#include "VAdderTree16__Syms.h"


//--------------------


void VAdderTree16::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAdderTree16::eval\n"); );
    VAdderTree16__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VAdderTree16::_eval_initial_loop(VAdderTree16__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VAdderTree16::_combo__TOP__1(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__1\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_2) ^ (IData)(vlTOPp->i_X_3)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_6) ^ (IData)(vlTOPp->i_X_7)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_10) ^ (IData)(vlTOPp->i_X_11)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->i_X_14) ^ (IData)(vlTOPp->i_X_15)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (1U & (((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->i_X_1) : (IData)(vlTOPp->i_X_3))));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__2(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__2\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_1) >> 1U)
		      : ((IData)(vlTOPp->i_X_3) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_1) >> 2U)
		      : ((IData)(vlTOPp->i_X_3) >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_1) >> 3U)
		      : ((IData)(vlTOPp->i_X_3) >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_1) 
			    >> 4U) : ((IData)(vlTOPp->i_X_3) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_1) 
			    >> 5U) : ((IData)(vlTOPp->i_X_3) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_1) 
			    >> 6U) : ((IData)(vlTOPp->i_X_3) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_1) 
			    >> 7U) : ((IData)(vlTOPp->i_X_3) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_1) 
			     >> 8U) : ((IData)(vlTOPp->i_X_3) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_1) 
			     >> 9U) : ((IData)(vlTOPp->i_X_3) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_0) ^ (IData)(vlTOPp->i_X_1)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_1) 
			     >> 0xaU) : ((IData)(vlTOPp->i_X_3) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (1U & (((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->i_X_5) : (IData)(vlTOPp->i_X_7))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_5) >> 1U)
		      : ((IData)(vlTOPp->i_X_7) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_5) >> 2U)
		      : ((IData)(vlTOPp->i_X_7) >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_5) >> 3U)
		      : ((IData)(vlTOPp->i_X_7) >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_5) 
			    >> 4U) : ((IData)(vlTOPp->i_X_7) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_5) 
			    >> 5U) : ((IData)(vlTOPp->i_X_7) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_5) 
			    >> 6U) : ((IData)(vlTOPp->i_X_7) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_5) 
			    >> 7U) : ((IData)(vlTOPp->i_X_7) 
				      >> 7U)) << 7U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__3(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__3\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_5) 
			     >> 8U) : ((IData)(vlTOPp->i_X_7) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_5) 
			     >> 9U) : ((IData)(vlTOPp->i_X_7) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_4) ^ (IData)(vlTOPp->i_X_5)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_5) 
			     >> 0xaU) : ((IData)(vlTOPp->i_X_7) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (1U & (((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->i_X_9) : (IData)(vlTOPp->i_X_11))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_9) >> 1U)
		      : ((IData)(vlTOPp->i_X_11) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_9) >> 2U)
		      : ((IData)(vlTOPp->i_X_11) >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_9) >> 3U)
		      : ((IData)(vlTOPp->i_X_11) >> 3U)) 
		    << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_9) 
			    >> 4U) : ((IData)(vlTOPp->i_X_11) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_9) 
			    >> 5U) : ((IData)(vlTOPp->i_X_11) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_9) 
			    >> 6U) : ((IData)(vlTOPp->i_X_11) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_9) 
			    >> 7U) : ((IData)(vlTOPp->i_X_11) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_9) 
			     >> 8U) : ((IData)(vlTOPp->i_X_11) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_9) 
			     >> 9U) : ((IData)(vlTOPp->i_X_11) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_8) ^ (IData)(vlTOPp->i_X_9)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_9) 
			     >> 0xaU) : ((IData)(vlTOPp->i_X_11) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (1U & (((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->i_X_13) : (IData)(vlTOPp->i_X_15))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_13) >> 1U)
		      : ((IData)(vlTOPp->i_X_15) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_13) >> 2U)
		      : ((IData)(vlTOPp->i_X_15) >> 2U)) 
		    << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->i_X_13) >> 3U)
		      : ((IData)(vlTOPp->i_X_15) >> 3U)) 
		    << 3U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__4(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__4\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_13) 
			    >> 4U) : ((IData)(vlTOPp->i_X_15) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_13) 
			    >> 5U) : ((IData)(vlTOPp->i_X_15) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_13) 
			    >> 6U) : ((IData)(vlTOPp->i_X_15) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->i_X_13) 
			    >> 7U) : ((IData)(vlTOPp->i_X_15) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_13) 
			     >> 8U) : ((IData)(vlTOPp->i_X_15) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_13) 
			     >> 9U) : ((IData)(vlTOPp->i_X_15) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->i_X_12) ^ (IData)(vlTOPp->i_X_13)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->i_X_13) 
			     >> 0xaU) : ((IData)(vlTOPp->i_X_15) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)
		      : ((IData)(vlTOPp->i_X_0) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->i_X_0) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->i_X_0) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->i_X_0) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->i_X_0) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->i_X_0) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->i_X_0) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->i_X_0) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->i_X_0) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->i_X_0) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)
		      : ((IData)(vlTOPp->i_X_4) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->i_X_4) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->i_X_4) 
				   >> 3U)) << 3U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__5(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__5\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->i_X_4) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->i_X_4) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->i_X_4) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->i_X_4) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->i_X_4) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->i_X_4) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->i_X_4) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)
		      : ((IData)(vlTOPp->i_X_8) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->i_X_8) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->i_X_8) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->i_X_8) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->i_X_8) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->i_X_8) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->i_X_8) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->i_X_8) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->i_X_8) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->i_X_8) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)
		      : ((IData)(vlTOPp->i_X_12) >> 1U)) 
		    << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->i_X_12) 
				   >> 2U)) << 2U)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__6(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__6\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->i_X_12) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->i_X_12) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->i_X_12) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->i_X_12) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->i_X_12) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->i_X_12) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->i_X_12) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->i_X_12) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum = 
	((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT___zz_1 = ((0x800U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0__DOT__c_out) 
						  << 1U)) 
				       | (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum));
    vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry)) 
	   | (1U & ((IData)(vlTOPp->i_X_0) & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_sum)))));
    vlTOPp->AdderTree16__DOT___zz_2 = ((0x800U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1__DOT__c_out) 
						  << 1U)) 
				       | (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum));
    vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
	   | (1U & ((IData)(vlTOPp->i_X_4) & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_sum)))));
    vlTOPp->AdderTree16__DOT___zz_3 = ((0x800U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2__DOT__c_out) 
						  << 1U)) 
				       | (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum));
    vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry)) 
	   | (1U & ((IData)(vlTOPp->i_X_8) & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_sum)))));
    vlTOPp->AdderTree16__DOT___zz_4 = ((0x800U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3__DOT__c_out) 
						  << 1U)) 
				       | (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum));
    vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
	   | (1U & ((IData)(vlTOPp->i_X_12) & (~ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_sum)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 4U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_3) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT___zz_4)) 
		 >> 0xbU));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c0_xor_d0 
	= (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		 ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 1U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 2U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 3U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 4U));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__7(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__7\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 5U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 6U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 7U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 8U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 9U));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d 
	= (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_2_o_carry) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry)) 
		 >> 0xaU));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xffeU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (1U & (((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xffeU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->AdderTree16__DOT___zz_2)
		     : (IData)(vlTOPp->AdderTree16__DOT___zz_4))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xffdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xffbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xff7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			 >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xfefU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			    >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xfdfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xfbfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xf7fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			    >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xeffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			     >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xdffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0xbffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			     >> 0xaU) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT___zz_2)) 
		  >> 0xbU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out 
	= ((0x7ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT___zz_2) 
			     >> 0xbU) : ((IData)(vlTOPp->AdderTree16__DOT___zz_4) 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum = 
	((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_sum)) 
	 | (1U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c0_xor_d0))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7feU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (1U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c0_xor_d0)
		     ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)
		     : (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 1U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				   >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 2U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7fbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 3U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
}

VL_INLINE_OPT void VAdderTree16::_combo__TOP__8(VAdderTree16__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdderTree16::_combo__TOP__8\n"); );
    VAdderTree16* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7f7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			 >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 4U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7efU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			    >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 5U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7dfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 6U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x7bfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 7U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x77fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			    >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 8U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x6ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			     >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 9U) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x5ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd 
	= (1U & ((((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry)) 
		  >> 0xaU) ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)));
    vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out 
	= ((0x3ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__c_xor_d)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_1_o_carry) 
			     >> 0xaU) : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_3_o_carry) 
					 >> 0xaU)) 
			<< 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xffdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)
		      : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
			 >> 1U)) << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xffbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			 >> 1U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				   >> 2U)) << 2U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xff7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			 >> 2U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				   >> 3U)) << 3U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xfefU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			    >> 3U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				      >> 4U)) << 4U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xfdfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			    >> 4U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				      >> 5U)) << 5U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xfbfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			    >> 5U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				      >> 6U)) << 6U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xf7fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			 ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			    >> 6U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				      >> 7U)) << 7U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xeffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			     >> 7U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				       >> 8U)) << 8U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xdffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			     >> 8U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				       >> 9U)) << 9U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0xbffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			     >> 9U) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
				       >> 0xaU)) << 0xaU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry 
	= ((0x7ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_carry)) 
	   | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
			  ? ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
			     >> 0xaU) : ((IData)(vlTOPp->AdderTree16__DOT___zz_1) 
					 >> 0xbU)) 
			<< 0xbU)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xffdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   ^ (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out)) 
		  << 1U)));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xffbU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (4U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__1__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 2U) ^ (0xfffffffcU & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xff7U & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (8U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__2__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		   << 3U) ^ (0xfffffff8U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					    << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xfefU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x10U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__3__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 4U) ^ (0xfffffff0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xfdfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x20U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__4__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 5U) ^ (0xffffffe0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xfbfU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x40U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__5__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 6U) ^ (0xffffffc0U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xf7fU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x80U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__6__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		      << 7U) ^ (0xffffff80U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
					       << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xeffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x100U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__7__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 8U) ^ (0xffffff00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xdffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x200U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__8__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 9U) ^ (0xfffffe00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
						<< 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0xbffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x400U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__9__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xaU) ^ (0xfffffc00U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum = 
	((0x7ffU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0_o_sum)) 
	 | (0x800U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__CSA42_unit__BRA__10__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd) 
		       << 0xbU) ^ (0xfffff800U & ((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_0__DOT__c_out) 
						  << 1U)))));
    vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry 
	= ((0x7fdU & (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1_o_carry)) 
	   | (2U & (((IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__CSA42_unit__BRA__0__KET____DOT__U_CSA42_UNIT__DOT__ab_xor_cd)
		      ? (IData)(vlTOPp->AdderTree16__DOT__csaArray_1_1__DOT__c_out)
		      : ((IData)(vlTOPp->AdderTree16__DOT__csaArray_0_0_o_carry) 
			 >> 1U)) << 1U)));
}
