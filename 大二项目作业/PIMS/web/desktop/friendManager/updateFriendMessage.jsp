<%-- 
    Document   : updateFriendMessage
    Created on : 2018-6-20, 20:52:43
    Author     : xxx_032
--%>



<%@page import="friendManager.LookFriendBean"%>
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
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp"><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>"><span></span>About yourself</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/List.jsp"  class="current"><span></span>List</a></li>
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
            	<h2>About u'Contracts</h2>
                <ul class="sidebar_nav">
                    <li><a href="http://localhost:8080/PIMS/desktop/friendManager/addFriend.jsp">add Contacts.</a></li>
                    <li><a href="http://localhost:8080/PIMS/LookFriendServlet">View the List.</a></li>
                    <li><a href="http://localhost:8080/PIMS/desktop/friendManager/updateFriend.jsp">correct Contacts.</a></li>
                    <li><a href="http://localhost:8080/PIMS/desktop/friendManager/deleteFriend.jsp">delete Contacts.</a></li>
                </ul>
            </div>      
        </div> <!-- end of sidebar -->
        
        <div id="tooplate_content">

            <div class="col_fw">
            <table class="table" cellspacing="0" align="center">
                <tr>

                    <th width="100%" >update your Contracts.</th>
                </tr>
            </table>
            
            <form action="http://localhost:8080/PIMS/UpdateFriendMessageServlet" method="post">
            <table class="table" cellspacing="0">
            <%
                ArrayList friendslist2=(ArrayList)session.getAttribute("friendslist2");
                if(friendslist2==null||friendslist2.size()==0){
                    response.sendRedirect("http://localhost:8080/PIMS/friendManager/lookFriend.jsp");
                }else{
                    for(int i=friendslist2.size()-1;i>=0;i--){
                        LookFriendBean ff=(LookFriendBean)friendslist2.get(i);
            %>
                <tr>
                    <td height="30">用户姓名</td>
                    <td><%=ff.getName()%></td>
                </tr>
                <tr>
                    <td height="30">用户电话</td>
                    <td><input type="text" name="phone" value="<%=ff.getPhone()%>"></td>
                </tr>
                <tr>
                    <td height="30">邮箱地址</td>
                    <td><input type="text" name="email" value="<%=ff.getEmail()%>"></td>
                </tr>
                <tr>
                    <td height="30">工作单位</td>
                    <td><input type="text" name="workPlace" value="<%=ff.getWorkPlace()%>"></td>
                </tr>
                <tr>
                    <td height="30">家庭住址</td>
                    <td><input type="text" name="place" value="<%=ff.getPlace()%>"></td>
                </tr>
                <tr>
                    <td height="30">用户QQ</td>
                    <td><input type="text" name="QQ" value="<%=ff.getQQ()%>"></td>
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


