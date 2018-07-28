/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fileManager;

import friendManager.LookFriendBean;
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

/**
 *
 * @author xxx_032
 */
public class lookFileServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
          try{
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                String userName="";
                HttpSession session=request.getSession();
                ArrayList login=(ArrayList)session.getAttribute("login");
                if(login==null||login.size()==0){
                       response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
                }else{
                    for(int i=login.size()-1;i>=0;i--){
                        LoginBean nn=(LoginBean)login.get(i);
                        userName=nn.getUserName();
                    }
                }
                String sql1="select * from file where userName='"+userName+"'";
                rs=stmt.executeQuery(sql1);
                ArrayList Filelist=null;
                    Filelist=new ArrayList();
                    while(rs.next()){
                        LookFileBean ff=new LookFileBean();
                        ff.setUserName(rs.getString("userName"));
                        ff.setName(rs.getString("name"));
                        ff.setContentType(rs.getString("contentType"));
                        ff.setSize(rs.getString("size"));
                        ff.setFilePath(rs.getString("filePath"));
                        Filelist.add(ff);
                        session.setAttribute("Filelist", Filelist);
                     }
                    if(Filelist == null||Filelist.size()==0){
                        session.setAttribute("Filelist", Filelist);
                    }
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/desktop/fileManager/lookFile.jsp");
            }catch(Exception e){
                e.printStackTrace();
            }
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
        doGet(request, response);
    }

}
