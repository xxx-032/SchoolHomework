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
public class UpdateFriendMessageServlet extends HttpServlet {


    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        String phone= request.getParameter("phone");
        String email= request.getParameter("email");
        String workPlace= request.getParameter("workPlace");
        String place= request.getParameter("place");
        String QQ= request.getParameter("QQ");
        if(phone.length()==0||email.length()==0||workPlace.length()==0||place.length()==0||QQ.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/updateFriendMessage.jsp");
        }else{
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
                String name=null;
                ArrayList friendslist3=(ArrayList)session.getAttribute("friendslist3");
                if(friendslist3==null||friendslist3.size()==0){
                    response.sendRedirect("http://localhost:8080/PIMS/desktop/main");
                }else{
                    for(int i=friendslist3.size()-1;i>=0;i--){
                        UpdateFriendBean ff=(UpdateFriendBean)friendslist3.get(i);
                        name=ff.getName();
                    }
                }
                String sql1="update friends set phone='"+phone+"',email='"+email+"',workPlace='"+workPlace+"',place='"+place+"',QQ='"+QQ+"' where name='"+name+"'and userName='"+userName+"'";
                stmt.executeUpdate(sql1);
                String sql2="select * from friends where userName='"+userName+"'";
                rs=stmt.executeQuery(sql2);
                ArrayList friendslist=null;
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
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/LookFriendServlet");
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