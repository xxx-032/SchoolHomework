<%-- 
    Document   : resgister
    Created on : 2018-6-18, 15:56:57
    Author     : xxx_032
--%>

<%@ page contentType="text/html; charset=UTF-8" %>  
<!DOCTYPE html>
<html>
<head>
<title>register</title>
<!-- Meta tags -->
	<meta name="viewport" content="width=device-width, initial-scale=1" />
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="keywords" content="package signup Form Responsive Widget,Login form widgets, Sign up Web forms , Login signup Responsive web form,Flat Pricing table,Flat Drop downs,Registration Forms,News letter Forms,Elements" />
<script type="application/x-javascript"> addEventListener("load", function() { setTimeout(hideURLbar, 0); }, false);
function hideURLbar(){ window.scrollTo(0,1); } </script>
<!-- Meta tag Keywords -->
<link href="http://localhost:8080/PIMS/register/css/return.css" rel="stylesheet" type="text/css" media="all">
<link href="http://localhost:8080/PIMS/register/css/style.css" rel="stylesheet" type="text/css" media="all">
<link href="//fonts.googleapis.com/css?family=Montserrat:100,200,300,400,500,600,700,800,900&amp;subset=cyrillic,cyrillic-ext,latin-ext,vietnamese" rel="stylesheet">
</head>
<body>
<div class="form">
<h1>Register to PIMS</h1>
	<div class="form-content">
		<form action="http://localhost:8080/PIMS/RegisterServlet" method="post">
			<div class="form-info">
<div class="form-info">
				<h2>Signup</h2>
			</div>
			<div class="name">
				<label>UserName</label>
				<input class="input1" type="text" name="userName" placeholder="userName" required="">
			</div>
			<div class="email">
				<label>Email</label>
				<input class="input1" type="email" name="email" placeholder="Email" required="">
			</div>
			<div class="pass1">
				<label>Password</label>
				<input class="input1" type="password" name="password" placeholder="**********" required="">
			</div>
			<div class="pass2">
				<label>Re-Password</label>
				<input class="input1" type="password" name="confirm_pasdsword" placeholder="**********" required="">
			</div>
                        <div class="pass3">
				<label>Name</label>
				<input class="input1" type="text" name="name" placeholder="Name" required="">
			</div>
                        <div class="pass4">
				<label>Gender</label>
				<input type="radio" name="sex" value="男" checked>男
                                <input type="radio" name="sex" value="女">女
			</div>
                        <div class="pass5">
				<label>data of birth</label>
				<select name="year" size="1">
                                        <option value="1978">1978</option>
                                        <option value="1979">1979</option>
                                        <option value="1980">1980</option>
                                        <option value="1981">1981</option>
                                        <option value="1982">1982</option>
                                        <option value="1983">1983</option>
                                        <option value="1984">1984</option>
                                        <option value="1985">1985</option>
                                        <option value="1986">1986</option>
                                        <option value="1987">1987</option>
                                        <option value="1988">1988</option>
                                        <option value="1989">1989</option>
                                        <option value="1990">1990</option>
                                        <option value="1991">1991</option>
                                        <option value="1992">1992</option>
                                        <option value="1993">1993</option>
                                        <option value="1994">1994</option>
                                        <option value="1995">1995</option>
                                        <option value="1996">1996</option>
                                        <option value="1997">1997</option>
                                        <option value="1998">1998</option>
                                        <option value="1999">1999</option>
                                        <option value="2000">2000</option>
                                        <option value="2001">2001</option>
                                        <option value="2002">2002</option>
                                        <option value="2003">2003</option>
                                        <option value="2004">2004</option>
                                        <option value="2005">2005</option>
                                        <option value="2006">2006</option>
                                        <option value="2007">2007</option>
                                        <option value="2008">2008</option>
                                        <option value="2008">2008</option>
                                        <option value="2009">2009</option>
                                        <option value="2010">2010</option>
                                        <option value="2011">2011</option>
                                        <option value="2012">2012</option>
                                        <option value="2013">2013</option>
                                        <option value="2014">2014</option>
                                        <option value="2015">2015</option>
                                        <option value="2016">2016</option>
                                        <option value="2017">2017</option>
                                        <option value="2018">2018</option>
                                    </select>年
                                    <select name="month" size="1">
                                        <option value="01">01</option>
                                        <option value="02">02</option>
                                        <option value="03">03</option>
                                        <option value="04">04</option>
                                        <option value="05">05</option>
                                        <option value="06">06</option>
                                        <option value="07">07</option>
                                        <option value="08">08</option>
                                        <option value="09">09</option>
                                        <option value="10">10</option>
                                        <option value="11">11</option>
                                        <option value="12">12</option>
                                    </select>月
                                    <select name="day" size="1">
                                        <option value="01">01</option>
                                        <option value="02">02</option>
                                        <option value="03">03</option>
                                        <option value="04">04</option>
                                        <option value="05">05</option>
                                        <option value="06">06</option>
                                        <option value="07">07</option>
                                        <option value="08">08</option>
                                        <option value="09">09</option>
                                        <option value="10">10</option>
                                        <option value="11">11</option>
                                        <option value="12">12</option>
                                        <option value="13">13</option>
                                        <option value="14">14</option>
                                        <option value="15">15</option>
                                        <option value="16">16</option>
                                        <option value="17">17</option>
                                        <option value="18">18</option>
                                        <option value="19">19</option>
                                        <option value="20">20</option>
                                        <option value="21">21</option>
                                        <option value="22">22</option>
                                        <option value="23">23</option>
                                        <option value="24">24</option>
                                        <option value="25">25</option>
                                        <option value="26">26</option>
                                        <option value="27">27</option>
                                        <option value="28">28</option>
                                        <option value="29">29</option>
                                        <option value="30">30</option>
                                        <option value="31">31</option>
                                    </select>日
			</div>
                        <div class="pass6">
				<label>Nation</label>
				<input type="radio" name="nation" value="汉族" checked>汉族
                                <input type="radio" name="nation" value="回族">回族
                                <input type="radio" name="nation" value="壮族">壮族
                                <input type="radio" name="nation" value="其它">其它
			</div>
                    
                        <div class="pass7">
				<label>Education</label>
				<select name="edu" size="1">
                                        <option value="博士">博士</option>
                                        <option value="硕士">硕士</option>
                                        <option value="本科">本科</option>
                                        <option value="专科">专科</option>
                                        <option value="高中">高中</option>
                                        <option value="初中">初中</option>
                                        <option value="小学">小学</option>
                                        <option value="其它">其它</option>
                                </select>
			</div>
                        <div class="pass8">
				<label>Positional</label>
				<select name="work" size="1">
                                        <option value="软件开发工程师">软件开发工程师</option>
                                        <option value="软件测试工程师">软件测试工程师</option>
                                        <option value="教师">教师</option>
                                        <option value="学生">学生</option>
                                        <option value="经理">经理</option>
                                        <option value="职员">职员</option>
                                        <option value="老板">老板</option>
                                        <option value="公务员">公务员</option>
                                        <option value="其它">其它</option>
                                </select>
			</div>
                        <div class="pass9">
				<label>PhoneNumber</label>
				<input class="input1" type="text" name="phone" placeholder="PhoneNumber" required="">
			</div>
                        <div class="pass10">
				<label>Address</label>
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
			</div>
                    
                        <div class="sub-w3l">
                        <a href="http://localhost:8080/PIMS/login/login.jsp">Return to login.</a>     
                        <div class="clear"></div>
                        </div>
			<div class="signup">
				<input type="submit" value="Sign Up">
			</div>
		</form>
	</div>
</div>
<footer>&copy;. All rights reserved by DGUT.</footer>
</body>
</html>