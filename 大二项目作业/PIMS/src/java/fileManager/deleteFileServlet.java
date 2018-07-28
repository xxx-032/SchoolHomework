/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fileManager;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import loginRegister.LoginBean;
import loginRegister.connectToSQL;
import loginRegister.localUser;

/**
 *
 * @author xxx_032
 */
public class deleteFileServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        
        HttpSession session=request.getSession();
        ArrayList login=(ArrayList)session.getAttribute("login");
        if(login==null||login.size()==0){
            response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }        
        
    try{
        
                response.setContentType("text/html;charset = utf-8");
                request.setCharacterEncoding("utf-8");
                Connection con=null;
                Statement stmt=null;
                String fileName = request.getParameter("fileName");           
                String FilePath = request.getParameter("FilePath");
                String path = FilePath + "/" + fileName;
                File file = new File(path);
                    // 如果文件路径所对应的文件存在，并且是一个文件，则直接删除
                if (file.exists()) {
                      file.delete();
                      while(file.exists()){
                           file.delete();
                           System.gc();
                      }
                }
                
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                
                String sql1="delete from file where userName='"+localUser.username+"'" + "and name =" + "'" + fileName + "'" ;
                stmt.executeUpdate(sql1);
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/lookFileServlet");
            }catch(Exception e){
                e.printStackTrace();
            }
    }

   
    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
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
     *
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
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
