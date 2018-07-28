<%-- 
    Document   : updateMessage
    Created on : 2018-6-20, 19:27:37
    Author     : xxx_032
--%>


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
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp"><span></span>Home</a></li>
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

                    <th width="100%" >update your Message.</th>
                </tr>
            </table>
            <form action="http://localhost:8080/PIMS/UpdateMessageServlet" method="post">
            <table class="table" cellspacing="0">
            <%
                ArrayList wordlist=(ArrayList)session.getAttribute("wordlist");
                if(wordlist==null||wordlist.size()==0){
                    response.sendRedirect("http://localhost:8080/PIMS/main/bottom.jsp");
                }else{
                for(int i=wordlist.size()-1;i>=0;i--){
                    LookMessageBean mm=(LookMessageBean)wordlist.get(i);
             %>
                <tr>
                    <td height="30">用户姓名</td>
                    <td><%=mm.getName()%></td>
                </tr>
                <tr>
                    <td height="30">用户性别</td>
                    <td><%=mm.getSex()%></td>
                </tr>
                <tr>
                    <td height="30">出生日期</td>
                    <td><%=mm.getBirth()%></td>
                </tr>
                <tr>
                    <td height="30">用户民族</td>
                    <td><%=mm.getNation()%></td>
                </tr>
                <tr>
                    <td height="30">用户学历</td>
                    <td>
                        <select name="edu" size="1">
                            <%if(mm.getEdu().equals("博士")){%>
                            <option value="博士" selected>博士</option>
                            <%}else{%>
                            <option value="博士">博士</option>
                            <%}%>
                            <%if(mm.getEdu().equals("硕士")){%>
                            <option value="硕士" selected>硕士</option>
                            <%}else{%>
                            <option value="硕士">硕士</option>
                            <%}%>
                            <%if(mm.getEdu().equals("本科")){%>
                            <option value="本科" selected>本科</option>
                            <%}else{%>
                            <option value="本科">本科</option>
                            <%}%>
                            <%if(mm.getEdu().equals("专科")){%>
                            <option value="专科" selected>专科</option>
                            <%}else{%>
                            <option value="专科">专科</option>
                            <%}%>
                            <%if(mm.getEdu().equals("高中")){%>
                            <option value="高中" selected>高中</option>
                            <%}else{%>
                            <option value="高中">高中</option>
                            <%}%>
                            <%if(mm.getEdu().equals("初中")){%>
                            <option value="初中" selected>初中</option>
                            <%}else{%>
                            <option value="初中">初中</option>
                            <%}%>
                            <%if(mm.getEdu().equals("初中")){%>
                            <option value="初中" selected>初中</option>
                            <%}else{%>
                            <option value="初中">初中</option>
                            <%}%>
                            <%if(mm.getEdu().equals("小学")){%>
                            <option value="小学" selected>小学</option>
                            <%}else{%>
                            <option value="小学">小学</option>
                            <%}%>
                            <%if(mm.getEdu().equals("其它")){%>
                            <option value="其它" selected>其它</option>
                            <%}else{%>
                            <option value="其它">其它</option>
                            <%}%>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td height="30">用户职称</td>
                    <td>
                        <select name="work" size="1">
                            <%if(mm.getWork().equals("软件开发工程师")){%>
                            <option value="软件开发工程师" selected>软件开发工程师</option>
                            <%}else{%>
                            <option value="软件开发工程师">软件开发工程师</option>
                            <%}%>
                            <%if(mm.getWork().equals("软件测试工程师")){%>
                            <option value="软件测试工程师" selected>软件测试工程师</option>
                            <%}else{%>
                            <option value="软件测试工程师">软件测试工程师</option>
                            <%}%>
                            <%if(mm.getWork().equals("教师")){%>
                            <option value="教师" selected>教师</option>
                            <%}else{%>
                            <option value="教师">教师</option>
                            <%}%>
                            <%if(mm.getWork().equals("学生")){%>
                            <option value="学生" selected>学生</option>
                            <%}else{%>
                            <option value="学生">学生</option>
                            <%}%>
                            <%if(mm.getWork().equals("职员")){%>
                            <option value="职员" selected>职员</option>
                            <%}else{%>
                            <option value="职员">职员</option>
                            <%}%>
                            <%if(mm.getWork().equals("经理")){%>
                            <option value="经理" selected>经理</option>
                            <%}else{%>
                            <option value="经理">经理</option>
                            <%}%>
                            <%if(mm.getWork().equals("老板")){%>
                            <option value="老板" selected>老板</option>
                            <%}else{%>
                            <option value="老板">老板</option>
                            <%}%>
                            <%if(mm.getWork().equals("公务员")){%>
                            <option value="公务员" selected>公务员</option>
                            <%}else{%>
                            <option value="公务员">公务员</option>
                            <%}%>
                            <%if(mm.getWork().equals("其它")){%>
                            <option value="其它" selected>其它</option>
                            <%}else{%>
                            <option value="其它">其它</option>
                            <%}%>      
                        </select>
                    </td>
                </tr>
                <tr>
                    <td height="30">用户电话</td>
                    <td><input type="text" name="phone" value="<%=mm.getPhone()%>"></td>
                </tr>
                <tr>
                    <td height="30">家庭住址</td>
                    <td><%=mm.getPlace()%></td>
                </tr>
                <tr>
                    <td height="30">邮箱地址</td>
                    <td><input type="text" name="email" value="<%=mm.getEmail()%>"></td>
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
