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
import loginRegister.LoginBean;
import loginRegister.connectToSQL;

/**
 *
 * @author Administrator
 */
public class LookFriendServlet extends HttpServlet {
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
                String sql1="select * from friends where userName='"+userName+"'";
                rs=stmt.executeQuery(sql1);
                ArrayList friendslist=null;
                if((ArrayList)session.getAttribute("friendslist")==null){
                    friendslist=new ArrayList();
                    while(rs.next()){
                        LookFriendBean ff=new LookFriendBean();
                        ff.setName(rs.getString("name"));
                        ff.setPhone(rs.getString("phone"));
                        ff.setEmail(rs.getString("email"));
                        ff.setWorkPlace(rs.getString("workPlace"));
                        ff.setPlace(rs.getString("place"));
                        ff.setQQ(rs.getString("QQ"));
                        friendslist.add(ff);
                        session.setAttribute("friendslist", friendslist);
                     }
                }
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/lookFriend.jsp");
            }catch(Exception e){
                e.printStackTrace();
            }
    } 

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        doGet(request, response);
    }

}