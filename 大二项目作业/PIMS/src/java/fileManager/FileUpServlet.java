/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package fileManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;
import loginRegister.connectToSQL;
import loginRegister.localUser;

/**
 *
 * @author Administrator
 */
@MultipartConfig(location = "E:\\temp")
public class FileUpServlet extends HttpServlet {
   private static final long serialVersionUID = 1L;
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        HttpSession session=request.getSession();
        ArrayList login=(ArrayList)session.getAttribute("login");
        if(login==null||login.size()==0){
                       response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }        
        
        
       Part part = request.getPart("file1");
        String filename = null;
    //Content-Disposition: 就是当用户想把请求所得的内容存为一个文件的时候提供一个默认的文件名
    //Content-Disposition：告诉浏览器以下载的方式打开文件
    for (String content : part.getHeader("content-disposition").split(";")) {
      System.out.println(content);
      //取得文件名
      if (content.trim().startsWith("filename")) {
        //截取文件名
        filename = content.substring(
            content.indexOf('=') + 1).trim().replace("\"", "");
      }
    }
    //输出流
     OutputStream out = null;
     //输入流
     InputStream filecontent = null;
     //File.separator 取得系统的分割线等数据
     String filepath="E:\\temp\\" + localUser.username;
     File file=new File(filepath);
     if(!file.exists()){
        file.mkdir();
     }
     out = new FileOutputStream(new File(filepath + File.separator + filename));
     int read;
    //获得一个输入流
    filecontent = part.getInputStream();
    final byte[] bytes = new byte[1024];
     
    while ((read = filecontent.read(bytes)) != -1) {
      out.write(bytes, 0, read);
    }

    try{
        
                
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                
                
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();

                
                String sql1="select * from file where userName='"+localUser.username+"'" + "and name =" + "'" + filename + "'" ;
                rs=stmt.executeQuery(sql1);
                rs.last();
                int k=rs.getRow();
                if (k>0){
                    rs.close();
                    stmt.close();
                    con.close();
                    response.sendRedirect("http://localhost:8080/PIMS/lookFileServlet");
                }
                else{
                String sql2="insert into file"+"(userName,name,contentType,size,filePath)"+"values("+"'"+ localUser.username +"'"+ "," + "'" + filename + "'" + "," + "'" + part.getContentType() +"'"+","+"'"+part.getSize() +"'"+","+"'E:/temp'"+")";
                stmt.executeUpdate(sql2);
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/lookFileServlet");
                }
            }catch(Exception e){
                e.printStackTrace();
            }
    
    
    
    
    }
    

    
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /** 
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Returns a short description of the servlet.
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>
}
