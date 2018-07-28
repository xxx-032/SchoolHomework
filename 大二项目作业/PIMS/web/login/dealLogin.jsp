<%-- 
    Document   : dealLogin
    Created on : 2018-6-23, 12:14:29
    Author     : xxx_032
--%>


<%@page import="loginRegister.localUser"%>
<%@ page contentType="text/html; charset=UTF-8" %>  
<html lang="en">

<head>
	<title>Login to PIMS</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="keywords" content="Creative Login Form Responsive Widget,Login form widgets, Sign up Web forms , Login signup Responsive web form,Flat Pricing table,Flat Drop downs,Registration Forms,News letter Forms,Elements"
	/>
	<script type="application/x-javascript">
		addEventListener("load", function () {
			setTimeout(hideURLbar, 0);
		}, false);

		function hideURLbar() {
			window.scrollTo(0, 1);
		}
	</script>

	<link rel="stylesheet" href="http://localhost:8080/PIMS/login/css/style.css" type="text/css" media="all" />
	<link rel="stylesheet" href="http://localhost:8080/PIMS/login/css/font-awesome.css">
	<link href="//fonts.googleapis.com/css?family=Roboto:100,100i,300,300i,400,400i,500,500i,700,700i,900,900i" rel="stylesheet">
</head>

<body>
	<!--header-->
	<div class="header-w3l">
		<h1>
			<span>L</span>ogin
			<span>T</span>o
			<span>P</span>IMS</h1>
	</div>
	<!--//header-->
	<div class="main-content-agile">
		<div class="sub-main-w3">
			<h2>Login Here</h2>
			<form action="http://localhost:8080/PIMS/LoginServlet" method="post">
                                
                                <%
                                    localUser.error = request.getParameter("error");
                                    if(localUser.error.equals("3")){

                                %>
				<div class="pom-agile">
					<span class="fa fa-user-o" aria-hidden="true"></span>
					<input placeholder="UserName is not Exists" name="userName" class="user" type="text" required="">
				</div>
                                <div class="pom-agile">
					<span class="fa fa-key" aria-hidden="true"></span>
					<input placeholder="Password" name="password" class="pass" type="password" required="">
				</div>
                                <%}else if(localUser.error.equals("4")){%>
                                <div class="pom-agile">
					<span class="fa fa-user-o" aria-hidden="true"></span>
					<input placeholder="UserName" name="userName" class="user" type="text" required="">
				</div>
                                
				<div class="pom-agile">
					<span class="fa fa-key" aria-hidden="true"></span>
					<input placeholder="Password is not right" name="password" class="pass" type="password" required="">
				</div>
                                <%}%>
				<div class="sub-w3l">
					<div class="sub-agile">
						<input type="checkbox" id="bra  nd1" value="">
						<label for="brand1">
							<span></span>Remember me</label>
					</div>
					 <a href="http://localhost:8080/PIMS/register/register.jsp">Register to PIMS.</a> 
                                        
					<div class="clear"></div>
				</div>
				<div class="right-w3l">
					<input type="submit" value="Login">
				</div>
                            
			</form>
		</div>
	</div>
	<!--//main-->
	<!--footer-->
	<div class="footer">
		<p>&copy; Create by cmj in 2018.
		</p>
	</div>
	<!--//footer-->
</body>

</html>