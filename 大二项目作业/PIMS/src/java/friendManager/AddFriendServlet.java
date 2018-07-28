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
public class AddFriendServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        String name= request.getParameter("name");
        String phone= request.getParameter("phone");
        String email= request.getParameter("email");
        String workPlace= request.getParameter("workPlace");
        String place= request.getParameter("place");
        String QQ= request.getParameter("QQ");
        if(name.length()==0||phone.length()==0||email.length()==0||workPlace.length()==0||QQ.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/addFriend.jsp");
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
                String sql1="select * from friends where name='"+name+"'and userName='"+userName+"'";
                rs=stmt.executeQuery(sql1);
                rs.last();
                int k;
                k=rs.getRow();
                if(k>0){
                    response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/addFriend.jsp");
                }else{
                    String sql2="insert into friends"+"(userName,name,phone,email,workPlace,place,QQ)"+"values("+"'"+userName+"'"+","+"'"+name+"'"+","+"'"+phone+"'"+","+"'"+email+"'"+","+"'"+workPlace+"'"+","+"'"+place+"'"+","+"'"+QQ+"'"+")";
                    stmt.executeUpdate(sql2);
                }
                String sql3="select * from friends where userName='"+userName+"'";
                rs=stmt.executeQuery(sql3);
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
                response.sendRedirect("http://localhost:8080/PIMS/desktop/friendManager/lookFriend.jsp");
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