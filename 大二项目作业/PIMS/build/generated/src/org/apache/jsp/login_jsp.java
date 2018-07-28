package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

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
      response.setContentType("text/html;charset=UTF-8");
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
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>个人信息管理系统--登录页面</title>\n");
      out.write("        <style>\n");
      out.write("        <!--\n");
      out.write("            p1{font-family:华文行楷;font-size:20pt;color:blue;}\n");
      out.write("            h1{font-family: 华文行楷;font-size:40pt;color:red}\n");
      out.write("        -->\n");
      out.write("        </style>\n");
      out.write("    </head>\n");
      out.write("    <body bgcolor=\"#99aaee\">\n");
      out.write("        <table border=\"0\" width=\"100%\" cellspacing=\"0\" cellpadding=\"0\">\n");
      out.write("            <tr bgcolor=\"#99aaee\">\n");
      out.write("                <td align=\"center\">\n");
      out.write("                    <img src=\"images/top.gif\" alt=\"校训\" width=\"600\" height=\"100\">\n");
      out.write("                </td>\n");
      out.write("                <td colspan=\"1\" align=\"left\">\n");
      out.write("                    <h2>个人信息管理系统</h2>\n");
      out.write("                </td>\n");
      out.write("            </tr>\n");
      out.write("            <tr>\n");
      out.write("                <td colspan=\"2\">\n");
      out.write("                    <hr align=\"center\" width=\"100%\" size=\"20\" color=\"green\">\n");
      out.write("                </td>\n");
      out.write("            </tr>\n");
      out.write("            <tr>\n");
      out.write("                <td width=\"30%\" align=\"center\">\n");
      out.write("                    <img src=\"images/bottom.jpg\" alt=\"风景\" height=\"360\">\n");
      out.write("                </td>\n");
      out.write("                <td align=\"center\" bgcolor=\"#99aadd\" width=\"70%\">\n");
      out.write("                    <form action=\"http://localhost:8080/PIMS/LoginServlet\" method=\"post\">\n");
      out.write("                        <table border=\"2\" cellspacing=\"0\" cellpadding=\"0\" bgcolor=\"#95BDFF\" width=\"350\">\n");
      out.write("                            <tr align=\"center\">\n");
      out.write("                                <td align=\"center\" height=\"130\">\n");
      out.write("                                    输入用户姓名：<input type=\"text\" name=\"userName\" size=\"16\"/><br>\n");
      out.write("                                    <p></p>\n");
      out.write("                                    输入用户密码：<input type=\"password\" name=\"password\" size=\"18\"/><br>\n");
      out.write("                                </td>\n");
      out.write("                            </tr>\n");
      out.write("                            <tr>\n");
      out.write("                                <td>\n");
      out.write("                                    <input type=\"submit\" value=\"确 定\" size=\"12\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
      out.write("                                    <input type=\"reset\" value=\"清 除\" size=\"12\">\n");
      out.write("                                </td>\n");
      out.write("                            </tr>\n");
      out.write("                            <tr>\n");
      out.write("                                <td>\n");
      out.write("                                    <p align=\"center\"><a href=\"http://localhost:8080/PIMS/register/register.jsp\">注册</a></p>\n");
      out.write("                                </td>\n");
      out.write("                            </tr>\n");
      out.write("                        </table>\n");
      out.write("                    </form>\n");
      out.write("                </td>\n");
      out.write("            </tr>\n");
      out.write("        </table>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
      out.write("\n");
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
