package com.ssafy.bms;

public class DuplicateException extends Exception {
	DuplicateException() {
		System.err.println("com.ssafy.bms.DuplicateException: 데이터가 중복되었습니다.");
	}
}
