<%-- 
    Document   : addDate
    Created on : 2018-6-20, 21:18:00
    Author     : xxx_032
--%>




<%@page import="dateManager.LookDateBean"%>
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
<link href="css/tooplate_style.css" rel="stylesheet" type="text/css" />
    
</head>
<body id="subpage">
<div id="tooplate_wrapper">
    <div id="tooplate_header_sp">
        <div id="tooplate_menu">
            <ul>
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp" class="current"><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>"><span></span>About yourself</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/List.jsp"><span></span>List</a></li>
                <li><a href="http://localhost:8080/PIMS/LookDateServlet"><span></span>Plan</a></li>
                <li><a href="http://localhost:8080/PIMS/fileManager/fileUp.jsp"><span></span>File</a></li>
                <li><a href="http://localhost:8080/PIMS/login/login.jsp"><span></span>Exit</a></li>
            </ul>    	
        </div> <!-- end of tooplate_menu -->
        
        <div id="site_title"><h1><a href="#">Free Website Template</a></h1></div>
        
    </div> <!-- end of header -->
    
  <div id="tooplate_main">
    	
    	<div id="tooplate_sidebar">
        	<div class="sidebar_box">
            	<h2>About u'</h2>
                <ul class="sidebar_nav">
                    <li><a href="http://localhost:8080/PIMS/desktop/dateManager/addDate.jsp">add Meetings.</a></li>
                    <li><a href="http://localhost:8080/PIMS/LookDateServlet">View the Meetings.</a></li>
                    <li><a href="http://localhost:8080/PIMS/desktop/dateManager/updateDate.jsp">correct Meetings.</a></li>
                    <li><a href="http://localhost:8080/PIMS/desktop/dateManager/deleteDate.jsp">delete Meetings.</a></li>
                </ul>
            </div>      
        </div> <!-- end of sidebar -->
        
        <div id="tooplate_content">
       	  <!--
            <div class="col_fw">
            <h1>About Us</h1>
            <img src="images/tooplate_image_02.jpg" alt="Image 02" class="image_fl" />
            <p><em>Duis accumsan libero placerat mi facilisis posuere. Nunc ac quam diam. Duis non odio eros, pharetra ultrices justo. </em></p>
            <p>Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. <a href="#">Sed rhoncus</a> libero non tellus molestie et luctus orci faucibus. Duis faucibus tincidunt dui at molestie. Aliquam erat volutpat. Maecenas in purus quis leo posuere imperdiet. Donec nec nisl orci, in blandit est. Validate <a href="http://validator.w3.org/check?uri=referer" rel="nofollow"><strong>XHTML</strong></a> and <a href="http://jigsaw.w3.org/css-validator/check/referer" rel="nofollow"><strong>CSS</strong></a>.</p>
            </div>
		-->
            <div class="col_fw">
            <h1>emmm.</h1>
            
            <form action="http://localhost:8080/PIMS/AddDateServlet" method="post">
            <table class="table" cellspacing="0">
                <tr>
                     <td height="30" width="50%" align="right">日程时间</td>
                     <td width="50%">
                         20<input type="text" size="1" name="year" value="">年
                         <input type="text" size="1" name="month" value="">月
                         <input type="text" size="1" name="day" value="">日
                     </td>
                </tr>
                <tr>
                     <td height="30" width="50%" align="right">日程内容</td>
                     <td width="50%"><input type="text" size="30" name="thing" value=""></td>
                </tr>
                <tr>
                    <td colspan="2" align="center">
                        <input type="submit" value="确 定" size="12">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <input type="reset" value="清 除" size="12">
                    </td>
                </tr>
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