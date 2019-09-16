# Servlet & JSP Summary

## 쿠키
웹 서버에서 작은 양의 정보를 웹 브라우저에게 보내고, 웹 브라우저는 그 정보를 저장하고 있다가, 나중에 다시 이 웹페이지를 방문할 때 웹 서버에세 제출하도록 하는 것

쿠키는 일반적으로 세션 관리를 위해 사용된다

1. 클라이언트의 요청에 따라 웹 서버는 클라이언트에게 응답을 통해 쿠키를 부여한다
1. 쿠키가 사용자의 디스크나 웹 브라우저 메모리에 저장된다
1. 사용자가 쿠키를 부여 받은 웹사이트를 다시 요청할 때 쿠키가 전송되며 웹 서버는 해당 쿠키를 통해 클라이언트를 구별한다

## JSP 개요
Java Server Pages의 약어로, 웹페이지를 동적으로 처리할 수 있는 기술 중의 하나로 서블릿 프로그램의 기능을 HTML 팡리 내에 스크립트 형식으로 구현할 수 있다.
> HTML 파일 내에 스크립트 형식으로 구현

#### JSP의 처리 과정

### JSP의 스크립팅 요소(Scripting Element)
#### 스크립트릿(scriptlet)
```jsp
가장 많이 활용되는 JSP 구성 요소로서 JSP 페이지 내에서 java 코드 구현을 위해 사용한다
<% java code 작성 %>
```
#### 선언 (Declaration)
멤버변수 선언이나 메소드 선언에 사용
```jsp
<%! 속성 선언 및 method 작성 %>
```

#### 표현식 (Expression)
```jsp
<%= 출력할 값, 변수, 함수 결과 %>
```

#### 주석 (Comment)
```jsp
<%-- comment --%>
```

### JSP 기본 객체와 활성 범위
|메소드|리턴타입|설명|
|:--|:--|---|
|request|HttpServletRequest|HTML 폼 요소의 선택 값 등 사용자 입력 정보를 읽어올 때 사용|
|response|HttpServletResponse|사용자 요청에 대한 응답을 처리하기 위해 사용|
|pageContext|pageContext|각종 기본 객체를 얻거나 forward 및 include 기능을 활용할 때 사용|
|session HttpSession|클라이언트에 대한 세션 정보를 처리하기 위해 사용|
|application|ServletContext|웹 서버의 어플리케이션 처리와 관련된 정보를 참조하기 위해 사용|
|out|JspWriter|사용자에게 전달하기 위한 output 스트림을 처리할 때 사용|
|config|ServletConfig|현재 JSP에 대한 초기화 환경을 처리하기 위해 사용|
|page|java.lang.Object|현재 JSP페이지에 대한 참조 변수에 해당|