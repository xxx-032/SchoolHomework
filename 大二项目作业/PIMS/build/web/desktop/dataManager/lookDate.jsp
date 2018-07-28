<%-- 
    Document   : lookDate
    Created on : 2018-6-20, 21:18:16
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
                    <th width="40%">日程时间</th>
                    <th width="60%">日程内容</th>
              </tr>
              <%
                    ArrayList datelist=(ArrayList)session.getAttribute("datelist");
                    if(datelist==null||datelist.size()==0){
              %>
                <div align="center">
                    <h1>您还没有任何日程安排！</h1>
                </div>
                <%
            }else{
                for(int i=datelist.size()-1;i>=0;i--){
                    LookDateBean dd=(LookDateBean)datelist.get(i);
                    %>
                        <tr>
                            <td><%=dd.getDate()%></td>
                            <td><%=dd.getThing()%></td>
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