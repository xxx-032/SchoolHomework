<%-- 
    Document   : AboutYouselves
    Created on : 2018-6-19, 21:35:50
    Author     : xxx_032
--%>

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

    <link rel="stylesheet" link href="http://localhost:8080/PIMS/desktop/css/galleriffic-2.css" type="text/css" />

	<script type="text/javascript" src="js/jquery-1.3.2.js"></script>
    <script type="text/javascript" src="js/jquery.galleriffic.js"></script>
    
    <script type="text/javascript" src="js/jquery.opacityrollover.js"></script>
    <!-- We only want the thunbnails to display when javascript is disabled -->
    <script type="text/javascript">
    document.write('<style>.noscript { display: none; }</style>');
    </script>    
</head>
<body id="subpage">
<div id="tooplate_wrapper">
    <div id="tooplate_header_sp">
        <div id="tooplate_menu">
            <ul>
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp"><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>" class="current"><span></span>About yourself</a></li>
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
       	  <!--
            <div class="col_fw">
            <h1>About Us</h1>
            <img src="images/tooplate_image_02.jpg" alt="Image 02" class="image_fl" />
            <p><em>Duis accumsan libero placerat mi facilisis posuere. Nunc ac quam diam. Duis non odio eros, pharetra ultrices justo. </em></p>
            <p>Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. <a href="#">Sed rhoncus</a> libero non tellus molestie et luctus orci faucibus. Duis faucibus tincidunt dui at molestie. Aliquam erat volutpat. Maecenas in purus quis leo posuere imperdiet. Donec nec nisl orci, in blandit est. Validate <a href="http://validator.w3.org/check?uri=referer" rel="nofollow"><strong>XHTML</strong></a> and <a href="http://jigsaw.w3.org/css-validator/check/referer" rel="nofollow"><strong>CSS</strong></a>.</p>
            </div>
		-->
            <div class="col_fw">
            <h1>Something about your Meesage.</h1>
            <p><em>You can see,update and correct your message here. </em></p>
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
