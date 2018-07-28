/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package friendManager;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.swing.JOptionPane;
import loginRegister.connectToSQL;

/**
 *
 * @author Administrator
 */
public class UpdateFriendServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        String friendName= request.getParameter("friendName");
        if(friendName.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/updateFriend.jsp");
        }else{
            try{
                Connection con=null;
                Statement stmt=null;
                ResultSet rs=null;
                con = connectToSQL.conectToSql();
                stmt=con.createStatement();
                String sql1="select * from friends where name='"+friendName+"'";
                rs=stmt.executeQuery(sql1);
                rs.last();
                int k=rs.getRow();
                rs.beforeFirst();
                if(k<1){
                    response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/updateFriend.jsp");
                }else{
                    HttpSession session=request.getSession();
                    ArrayList login=(ArrayList)session.getAttribute("login");
                    if(login==null||login.size()==0){
                        response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
                    }       
                    ArrayList friendslist2=null;
                    friendslist2=new ArrayList();
                    while(rs.next()){
                        LookFriendBean ff=new LookFriendBean();
                        ff.setName(rs.getString("name"));
                        ff.setPhone(rs.getString("phone"));
                        ff.setEmail(rs.getString("email"));
                        ff.setWorkPlace(rs.getString("workPlace"));
                        ff.setPlace(rs.getString("place"));
                        ff.setQQ(rs.getString("QQ"));
                        friendslist2.add(ff);
                        session.setAttribute("friendslist2", friendslist2);
                      }
                      ArrayList friendslist3=null;
                      UpdateFriendBean nn=new UpdateFriendBean();
                      friendslist3=new ArrayList();
                      nn.setName(friendName);
                      friendslist3.add(nn);
                      session.setAttribute("friendslist3", friendslist3);
                }
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/updateFriendMessage.jsp");
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    } 

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        doGet(request, response);
    }

}