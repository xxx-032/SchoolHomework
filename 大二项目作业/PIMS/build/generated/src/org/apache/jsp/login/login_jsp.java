package org.apache.jsp.login;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import loginRegister.localUser;

public final class login_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html; charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("  \n");
      out.write("<html lang=\"en\">\n");
      out.write("\n");
      out.write("<head>\n");
      out.write("\t<title>Login to PIMS</title>\n");
      out.write("\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n");
      out.write("\t<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
      out.write("\t<meta name=\"keywords\" content=\"Creative Login Form Responsive Widget,Login form widgets, Sign up Web forms , Login signup Responsive web form,Flat Pricing table,Flat Drop downs,Registration Forms,News letter Forms,Elements\"\n");
      out.write("\t/>\n");
      out.write("\t<script type=\"application/x-javascript\">\n");
      out.write("\t\taddEventListener(\"load\", function () {\n");
      out.write("\t\t\tsetTimeout(hideURLbar, 0);\n");
      out.write("\t\t}, false);\n");
      out.write("\n");
      out.write("\t\tfunction hideURLbar() {\n");
      out.write("\t\t\twindow.scrollTo(0, 1);\n");
      out.write("\t\t}\n");
      out.write("\t</script>\n");
      out.write("\n");
      out.write("\t<link rel=\"stylesheet\" href=\"http://localhost:8080/PIMS/login/css/style.css\" type=\"text/css\" media=\"all\" />\n");
      out.write("\t<link rel=\"stylesheet\" href=\"http://localhost:8080/PIMS/login/css/font-awesome.css\">\n");
      out.write("\t<link href=\"//fonts.googleapis.com/css?family=Roboto:100,100i,300,300i,400,400i,500,500i,700,700i,900,900i\" rel=\"stylesheet\">\n");
      out.write("</head>\n");
      out.write("\n");
      out.write("<body>\n");
      out.write("\t<!--header-->\n");
      out.write("\t<div class=\"header-w3l\">\n");
      out.write("\t\t<h1>\n");
      out.write("\t\t\t<span>L</span>ogin\n");
      out.write("\t\t\t<span>T</span>o\n");
      out.write("\t\t\t<span>P</span>IMS</h1>\n");
      out.write("\t</div>\n");
      out.write("\t<!--//header-->\n");
      out.write("\t<div class=\"main-content-agile\">\n");
      out.write("\t\t<div class=\"sub-main-w3\">\n");
      out.write("\t\t\t<h2>Login Here</h2>\n");
      out.write("\t\t\t<form action=\"http://localhost:8080/PIMS/LoginServlet\" method=\"post\">\n");
      out.write("\n");
      out.write("\t\t\t\t<div class=\"pom-agile\">\n");
      out.write("\t\t\t\t\t<span class=\"fa fa-user-o\" aria-hidden=\"true\"></span>\n");
      out.write("\t\t\t\t\t<input placeholder=\"UserName\" name=\"userName\" class=\"user\" type=\"text\" required=\"\">\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t<div class=\"pom-agile\">\n");
      out.write("\t\t\t\t\t<span class=\"fa fa-key\" aria-hidden=\"true\"></span>\n");
      out.write("\t\t\t\t\t<input placeholder=\"Password\" name=\"password\" class=\"pass\" type=\"password\" required=\"\">\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t<div class=\"sub-w3l\">\n");
      out.write("\t\t\t\t\t<div class=\"sub-agile\">\n");
      out.write("\t\t\t\t\t\t<input type=\"checkbox\" id=\"bra  nd1\" value=\"\">\n");
      out.write("\t\t\t\t\t\t<label for=\"brand1\">\n");
      out.write("\t\t\t\t\t\t\t<span></span>Remember me</label>\n");
      out.write("\t\t\t\t\t</div>\n");
      out.write("\t\t\t\t\t <a href=\"http://localhost:8080/PIMS/register/register.jsp\">Register to PIMS.</a> \n");
      out.write("\t\t\t\t\t<div class=\"clear\"></div>\n");
      out.write("\t\t\t\t</div>\n");
      out.write("\t\t\t\t<div class=\"right-w3l\">\n");
      out.write("\t\t\t\t\t<input type=\"submit\" value=\"Login\">\n");
      out.write("\t\t\t\t</div>\n");
      out.write("                            \n");
      out.write("\t\t\t</form>\n");
      out.write("\t\t</div>\n");
      out.write("\t</div>\n");
      out.write("\t<!--//main-->\n");
      out.write("\t<!--footer-->\n");
      out.write("\t<div class=\"footer\">\n");
      out.write("\t\t<p>&copy; Create by cmj in 2018.\n");
      out.write("\t\t</p>\n");
      out.write("\t</div>\n");
      out.write("\t<!--//footer-->\n");
      out.write("</body>\n");
      out.write("\n");
      out.write("</html>");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
