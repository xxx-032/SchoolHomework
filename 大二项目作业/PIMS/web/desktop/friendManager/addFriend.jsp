<%-- 
    Document   : addFriend
    Created on : 2018-6-20, 20:52:04
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
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp" ><span></span>Home</a></li>
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

                    <th width="100%" >Add Contracts.</th>
                </tr>
            </table>
            <form action="http://localhost:8080/PIMS/AddFriendServlet" method="post">
            <table class="table" cellspacing="0">
                <tr>
                    <td>用户姓名</td>
                    <td><input type="text" name="name"/></td>
                </tr>
                <tr>
                    <td>用户电话</td>
                    <td><input type="text" name="phone"/></td>
                </tr>
                <tr>
                    <td>邮箱地址</td>
                    <td><input type="text" name="email"/></td>
                </tr>
                <tr>
                    <td>工作单位</td>
                    <td><input type="text" name="workPlace"/></td>
                </tr>
                <tr>
                    <td>家庭住址</td>
                    <td>
                        <select name="place" size="1">
                            <option value="北京">北  京</option>
                            <option value="上海">上  海</option>
                            <option value="天津">天  津</option>                          
                            <option value="河北">河  北</option>
                            <option value="河南">河  南</option>
                            <option value="吉林">吉  林</option>
                            <option value="黑龙江">黑龙江</option>
                            <option value="内蒙古">内蒙古</option>
                            <option value="山东">山  东</option>
                            <option value="山西">山  西</option>
                            <option value="陕西">陕  西</option>
                            <option value="甘肃">甘  肃</option>
                            <option value="宁夏">宁  夏</option>
                            <option value="青海">青  海</option>
                            <option value="新疆">新  疆</option>
                            <option value="辽宁">辽  宁</option>
                            <option value="江苏">江  苏</option>
                            <option value="浙江">浙  江</option>
                            <option value="安微">安  微</option>
                            <option value="广东">广  东</option>
                            <option value="海南">海  南</option>
                            <option value="广西">广  西</option>
                            <option value="云南">云  南</option>
                            <option value="贵州">贵  州</option>
                            <option value="四川">四  川</option>
                            <option value="重庆">重  庆</option>
                            <option value="西藏">西  藏</option>
                            <option value="香港">香  港</option>
                            <option value="澳门">澳  门</option>
                            <option value="福建">福  建</option>
                            <option value="江西">江  西</option>
                            <option value="湖南">湖  南</option>
                            <option value="青海">青  海</option>
                            <option value="湖北">湖  北</option>
                            <option value="台湾">台  湾</option>
                            <option value="其它">其  它</option>
                        </select>省(直辖市)
                    </td>
                </tr>
                <tr>
                    <td>用户QQ</td>
                    <td><input type="text" name="QQ"/></td>
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

