<%-- 
    Document   : lookFile
    Created on : 2018-6-20, 22:30:29
    Author     : xxx_032
--%>

<%@page import="fileManager.LookFileBean"%>
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
<link href="http://localhost:8080/PIMS/desktop/friendManager/css/table.css" rel="stylesheet" type="text/css" />


   <style type="text/css">
     button {  
        width: 57px;  
        padding:1px;  
        background-color: #428bca;  
        border-color: #357ebd;  
        color: #fff;  
        -moz-border-radius: 10px;  
        -webkit-border-radius: 10px;  
        border-radius: 50px; /* future proofing */  
        -khtml-border-radius: 10px; /* for old Konqueror browsers */  
        text-align: center;  
        vertical-align: middle;  
        border: 1px solid transparent;  
        font-weight: 20 px;  
        font-size:90%  
      }  
   </style>

</head>
<body id="subpage">
<div id="tooplate_wrapper">
    <div id="tooplate_header_sp">
        <div id="tooplate_menu">
            <ul>
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp"><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>"><span></span>About yourself</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/List.jsp"><span></span>List</a></li>
                <li><a href="http://localhost:8080/PIMS/LookDateServlet"><span></span>Plan</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/File.jsp"  class="current"><span></span>File</a></li>
                <li><a href="http://localhost:8080/PIMS/login/login.jsp"><span></span>Exit</a></li>
            </ul>    	
        </div> <!-- end of tooplate_menu -->
        
        <div id="site_title"><h1><a href="#">My PIMS WebSite</a></h1></div>
        
    </div> <!-- end of header -->
    
  <div id="tooplate_main">
    	
    	<div id="tooplate_sidebar">
        	<div class="sidebar_box">
            	<h2>About u'</h2>
                <ul class="sidebar_nav">
                    <li><a href="http://localhost:8080/PIMS/desktop/fileManager/fileUp.jsp">upload  File.</a></li>
                    <li><a href="http://localhost:8080/PIMS/lookFileServlet">File List.</a></li>
                </ul>
            </div>      
        </div> <!-- end of sidebar -->
        
         <div id="tooplate_content">

            <div class="col_fw">
                <h1>Personal Files.</h1>

            <table class="table" cellspacing="0" width="800">
            <%
                ArrayList Filelist=(ArrayList)session.getAttribute("Filelist");
                if(Filelist==null||Filelist.size()==0){
            %>
            <div align="center">
               <h1>您还没有任何文件！</h1>
            </div>
            <%
                }else{
             %>
            <tr>
                <th>用户姓名</th>
                <th>文件名</th>
                <th>文件类型</th>
                <th>文件大小</th>
                <th>文件所在路径</th>
                <th>下载文件</th>
                <th>删除文件</th>
            </tr>
             
             
             <%
                    for(int i=Filelist.size()-1;i>=0;i--){
                        LookFileBean ff=(LookFileBean)Filelist.get(i);
            %>
            <tr>
                <td><%=ff.getUserName()%></td>
                <td><%=ff.getName()%></td>
                <td><%=ff.getContentType()%></td>
                <td><%=ff.getSize()%></td>
                <td><%=ff.getFilePath()%></td>
                <td>
                <a href="http://localhost:8080/PIMS/FileDownServlet?destinationfileName=<%=ff.getName()%>&uploadPath=<%=ff.getFilePath() + "/" + localUser.username%>" method="post">
                <button >
                    U
                </button>
                </a>
                </td>
                <td>
                <a href="http://localhost:8080/PIMS/deleteFileServlet?fileName=<%=ff.getName()%>&FilePath=<%=ff.getFilePath() + "/" + localUser.username%>" method="post">
                <button >
                    D
                </button>
                </a>
                </td>
            </tr>
            <%
                  }
                }
            %>
        </table>
            
            
            
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

