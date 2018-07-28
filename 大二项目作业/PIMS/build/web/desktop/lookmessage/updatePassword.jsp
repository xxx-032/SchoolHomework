<%-- 
    Document   : updateMessage
    Created on : 2018-6-20, 19:27:37
    Author     : xxx_032
--%>


<%@page import="loginRegister.LoginBean"%>
<%@page import="lookMessage.LookMessageBean"%>
<%@page import="java.util.ArrayList"%>
<%@page import="loginRegister.localUser"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>About Yourself</title>
<meta name="keywords" content="" />
<meta name="description" content="" />
<link href="http://localhost:8080/PIMS/desktop/css/tooplate_style.css" rel="stylesheet" type="text/css" />
<link href="http://localhost:8080/PIMS/desktop/lookmessage/css/table.css" rel="stylesheet" type="text/css" />
<link href="http://localhost:8080/PIMS/desktop/lookmessage/css/button.css" rel="stylesheet" type="text/css" /> 
</head>
    
 
    
    
    
<body id="subpage">
<div id="tooplate_wrapper">
    <div id="tooplate_header_sp">
        <div id="tooplate_menu">
            <ul>
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp" ><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>"  class="current"><span></span>About yourself</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/List.jsp"><span></span>List</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/Plan.jsp"><span></span>Plan</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/File.jsp"><span></span>File</a></li>
                <li><a href="http://localhost:8080/PIMS/login/login.jsp"><span></span>Exit</a></li>
            </ul>    	
        </div> <!-- end of tooplate_menu -->
        
        <div id="site_title"><h1><a href="#">My PIMS WebSite</a></h1></div>
        
    </div> <!-- end of header -->
    
  <div id="tooplate_main">
    	
    	<div id="tooplate_sidebar">
        	<div class="sidebar_box">
            	<h2>About u'Message</h2>
                <ul class="sidebar_nav">
                    <li><a href="http://localhost:8080/PIMS/desktop/lookmessage/LookMessage.jsp">look about your Message.</a></li>
                        <li><a href="http://localhost:8080/PIMS/desktop/lookmessage/updateMessage.jsp">update your Message.</a></li>
                        <li><a href="http://localhost:8080/PIMS/desktop/lookmessage/updatePassword.jsp">correct your Password.</a></li>
                </ul>
            </div>      
        </div> <!-- end of sidebar -->
        
        <div id="tooplate_content">

            <div class="col_fw">
                <table class="table" cellspacing="0" align="center">
                <tr>

                    <th width="100%" >Correct your password.</th>
                </tr>
            </table>
            <form action="http://localhost:8080/PIMS/UpdatePasswordServlet" method="post">
            <table class="table" cellspacing="0">
            <%
                ArrayList login=(ArrayList)session.getAttribute("login");
                if(login==null||login.size()==0){
                    response.sendRedirect("http://localhost:8080/PIMS/main/bottom.jsp");
                }else{
                    for(int i=login.size()-1;i>=0;i--){
                        LoginBean nn=(LoginBean)login.get(i);
            %>
                <tr>
                    <td height="30">用户密码</td>
                    <td><input type="password" name="password" value="<%=nn.getPassword()%>"></td>
                </tr>
                <tr>        
                    <td height="30">重复密码</td>
                    <td><input type="password" name="confirm_pasdsword" value="<%=nn.getPassword()%>"></td>
                </tr>
                <tr>
                    <td colspan="2" align="center">
                        <input type="submit" value="确 定" size="12">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <input type="reset" value="清 除" size="12">
                    </td>
                 </tr>
            <%
                  }
               }
            %>
            </table>
       </form>
            
            
            </div>
            
                
                <div class="cleaner"></div>
			</div>
                      
        </div> <!-- end of content -->
        
        <div class="cleaner"></div>
    </div> <!-- end of main -->
    
</div> <!-- end of wrapper -->
<div id="tooplate_footer_wrapper">
    <div id="tooplate_footer">
        Copyright © 2018 Create by cmj.
        <div class="cleaner"></div>
    </div>
</div>  
        
</body>
</html>
