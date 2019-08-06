package com.ssafy.bms;

public class RecordNotFoundException extends Exception{
	RecordNotFoundException(){
		System.err.println("com.ssafy.bms.RecordNotFoundException: 데이터가 없습니다..");
	}
}
