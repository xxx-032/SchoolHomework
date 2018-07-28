package org.apache.jsp.desktop.fileManager;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import fileManager.LookFileBean;
import java.util.ArrayList;
import loginRegister.localUser;

public final class lookFile_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
      out.write("<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
      out.write("<head>\n");
      out.write("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
      out.write("<title>About Yourself</title>\n");
      out.write("<meta name=\"keywords\" content=\"\" />\n");
      out.write("<meta name=\"description\" content=\"\" />\n");
      out.write("<link href=\"http://localhost:8080/PIMS/desktop/css/tooplate_style.css\" rel=\"stylesheet\" type=\"text/css\" />\n");
      out.write("<link href=\"http://localhost:8080/PIMS/desktop/lookmessage/css/table.css\" rel=\"stylesheet\" type=\"text/css\" />\n");
      out.write("<link href=\"http://localhost:8080/PIMS/desktop/friendManager/css/table.css\" rel=\"stylesheet\" type=\"text/css\" />\n");
      out.write("\n");
      out.write("\n");
      out.write("   <style type=\"text/css\">\n");
      out.write("     button {  \n");
      out.write("        width: 57px;  \n");
      out.write("        padding:1px;  \n");
      out.write("        background-color: #428bca;  \n");
      out.write("        border-color: #357ebd;  \n");
      out.write("        color: #fff;  \n");
      out.write("        -moz-border-radius: 10px;  \n");
      out.write("        -webkit-border-radius: 10px;  \n");
      out.write("        border-radius: 50px; /* future proofing */  \n");
      out.write("        -khtml-border-radius: 10px; /* for old Konqueror browsers */  \n");
      out.write("        text-align: center;  \n");
      out.write("        vertical-align: middle;  \n");
      out.write("        border: 1px solid transparent;  \n");
      out.write("        font-weight: 20 px;  \n");
      out.write("        font-size:90%  \n");
      out.write("      }  \n");
      out.write("   </style>\n");
      out.write("\n");
      out.write("</head>\n");
      out.write("<body id=\"subpage\">\n");
      out.write("<div id=\"tooplate_wrapper\">\n");
      out.write("    <div id=\"tooplate_header_sp\">\n");
      out.write("        <div id=\"tooplate_menu\">\n");
      out.write("            <ul>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/desktop/main.jsp\"><span></span>Home</a></li>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/LookMessageServlet?userName=");
      out.print(localUser.username);
      out.write("\"><span></span>About yourself</a></li>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/desktop/List.jsp\"><span></span>List</a></li>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/LookDateServlet\"><span></span>Plan</a></li>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/desktop/File.jsp\"  class=\"current\"><span></span>File</a></li>\n");
      out.write("                <li><a href=\"http://localhost:8080/PIMS/login/login.jsp\"><span></span>Exit</a></li>\n");
      out.write("            </ul>    \t\n");
      out.write("        </div> <!-- end of tooplate_menu -->\n");
      out.write("        \n");
      out.write("        <div id=\"site_title\"><h1><a href=\"#\">My PIMS WebSite</a></h1></div>\n");
      out.write("        \n");
      out.write("    </div> <!-- end of header -->\n");
      out.write("    \n");
      out.write("  <div id=\"tooplate_main\">\n");
      out.write("    \t\n");
      out.write("    \t<div id=\"tooplate_sidebar\">\n");
      out.write("        \t<div class=\"sidebar_box\">\n");
      out.write("            \t<h2>About u'</h2>\n");
      out.write("                <ul class=\"sidebar_nav\">\n");
      out.write("                    <li><a href=\"http://localhost:8080/PIMS/desktop/fileManager/fileUp.jsp\">upload  File.</a></li>\n");
      out.write("                    <li><a href=\"http://localhost:8080/PIMS/lookFileServlet\">File List.</a></li>\n");
      out.write("                </ul>\n");
      out.write("            </div>      \n");
      out.write("        </div> <!-- end of sidebar -->\n");
      out.write("        \n");
      out.write("         <div id=\"tooplate_content\">\n");
      out.write("\n");
      out.write("            <div class=\"col_fw\">\n");
      out.write("                <h1>Personal Contracts.</h1>\n");
      out.write("\n");
      out.write("            <table class=\"table\" cellspacing=\"0\" width=\"800\">\n");
      out.write("            ");

                ArrayList Filelist=(ArrayList)session.getAttribute("Filelist");
                if(Filelist==null||Filelist.size()==0){
            
      out.write("\n");
      out.write("            <div align=\"center\">\n");
      out.write("               <h1>您还没有任何文件！</h1>\n");
      out.write("            </div>\n");
      out.write("            ");

                }else{
             
      out.write("\n");
      out.write("            <tr>\n");
      out.write("                <th>用户姓名</th>\n");
      out.write("                <th>文件名</th>\n");
      out.write("                <th>文件类型</th>\n");
      out.write("                <th>文件大小</th>\n");
      out.write("                <th>文件所在路径</th>\n");
      out.write("                <th>下载文件</th>\n");
      out.write("                <th>删除文件</th>\n");
      out.write("            </tr>\n");
      out.write("             \n");
      out.write("             \n");
      out.write("             ");

                    for(int i=Filelist.size()-1;i>=0;i--){
                        LookFileBean ff=(LookFileBean)Filelist.get(i);
            
      out.write("\n");
      out.write("            <tr>\n");
      out.write("                <td>");
      out.print(ff.getUserName());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(ff.getName());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(ff.getContentType());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(ff.getSize());
      out.write("</td>\n");
      out.write("                <td>");
      out.print(ff.getFilePath());
      out.write("</td>\n");
      out.write("                <td>\n");
      out.write("                <a href=\"http://localhost:8080/PIMS/FileDownServlet?destinationfileName=");
      out.print(ff.getName());
      out.write("&uploadPath=");
      out.print(ff.getFilePath() + "/" + localUser.username);
      out.write("\" method=\"post\">\n");
      out.write("                <button >\n");
      out.write("                    U\n");
      out.write("                </button>\n");
      out.write("                </a>\n");
      out.write("                </td>\n");
      out.write("                <td>\n");
      out.write("                <a href=\"http://localhost:8080/PIMS/deleteFileServlet?fileName=");
      out.print(ff.getName());
      out.write("&FilePath=");
      out.print(ff.getFilePath() + "/" + localUser.username);
      out.write("\" method=\"post\">\n");
      out.write("                <button >\n");
      out.write("                    D\n");
      out.write("                </button>\n");
      out.write("                </a>\n");
      out.write("                </td>\n");
      out.write("            </tr>\n");
      out.write("            ");

                  }
                }
            
      out.write("\n");
      out.write("        </table>\n");
      out.write("            \n");
      out.write("            \n");
      out.write("            \n");
      out.write("            </div>\n");
      out.write("            \n");
      out.write("                \n");
      out.write("                <div class=\"cleaner\"></div>\n");
      out.write("\t\t\t</div>\n");
      out.write("                      \n");
      out.write("        </div> <!-- end of content -->\n");
      out.write("        \n");
      out.write("        <div class=\"cleaner\"></div>\n");
      out.write("    </div> <!-- end of main -->\n");
      out.write("    \n");
      out.write("</div> <!-- end of wrapper -->\n");
      out.write("<div id=\"tooplate_footer_wrapper\">\n");
      out.write("    <div id=\"tooplate_footer\">\n");
      out.write("        Copyright © 2018 Create by cmj.\n");
      out.write("        <div class=\"cleaner\"></div>\n");
      out.write("    </div>\n");
      out.write("</div>  \n");
      out.write("        \n");
      out.write("</body>\n");
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
