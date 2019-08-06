package com.ssafy.bms;

import java.util.List;

public interface IBookMgr {

	/** file에서 객체를 읽어들이는 메서드 */
	public void load() ;
	
	/** file에 객체를 쓰는 메서드 */
	public void save() ;
	
	/** 도서 정보를  저장하는 매서드 */
	public void add(Book b) throws DuplicateException;
	
	/** 전체 데이터를 리턴하는 메서드 */
	public List<Book> search(); 
	
	/** ISBN를 이용하여 도서을 리턴하는 메서드 */
	public Book search(String isbn) throws RecordNotFoundException;  
	
	/** ISBN를 찾아 도서금액을 수정하는 메서드 */
	public void update(String isbn, int price) throws RecordNotFoundException;
	
	/** ISBN를 찾아 도서 정보를 삭제하는 메서드 */
	public void delete(String isbn) throws RecordNotFoundException;
	
	/** 전달된 파라메터의 단어를 포함하는 도서명을 구하여 리턴하는 메서드 */
	public List<Book> searchTitle(String title) ;
	
	/** ISBN을 기준으로 정렬하여 리턴하는 메서드 */
	public List<Book> sortIsbn();
	
	/** 등록된 도서명 중 가장 많이 나타나는 단어를 검색하여 리턴하는 메서드 */
	public  String   countWord();
	
}


