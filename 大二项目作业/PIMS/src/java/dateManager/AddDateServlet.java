/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dateManager;

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
public class AddDateServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset = utf-8");
        request.setCharacterEncoding("utf-8");
        
         
        
        String year= request.getParameter("year");
        String month= request.getParameter("month");
        String day= request.getParameter("day");
        String thing= request.getParameter("thing");
        String date= year + "-" + month + "-" + day;
        if(year.length()==0||month.length()==0||day.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/dateManager/addDate.jsp");
        }else if(year.length()!=4||Integer.parseInt(year)<11||Integer.parseInt(month)<1||Integer.parseInt(month)>12||Integer.parseInt(day)<1||Integer.parseInt(day)>31){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/dateManager/addDate.jsp");
        }else if(thing.length()==0){
            response.sendRedirect("http://localhost:8080/PIMS/desktop/dateManager/addDate.jsp");
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
                String sql1="select * from date where date='"+date+"'and userName='"+userName+"'";
                rs=stmt.executeQuery(sql1);
                rs.last();
                int k;
                k=rs.getRow();
                rs.beforeFirst();
                if(k>0){
                    response.sendRedirect("http://localhost:8080/PIMS/desktop/dateManager/addDate.jsp");
                }else{
                    String sql2="insert into date"+"(userName,date,thing)"+"values("+"'"+userName+"'"+","+"'"+date+"'"+","+"'"+thing+"'"+")";
                    stmt.executeUpdate(sql2);
                    String sql3="select * from date where userName='"+userName+"'";
                    rs=stmt.executeQuery(sql3);
                    ArrayList datelist=null;
                    datelist=new ArrayList();
                    while(rs.next()){
                        LookDateBean dd=new LookDateBean();
                        dd.setDate(rs.getString("date"));
                        dd.setThing(rs.getString("thing"));
                        datelist.add(dd);
                        session.setAttribute("datelist", datelist);
                     }
                }
                rs.close();
                stmt.close();
                con.close();
                response.sendRedirect("http://localhost:8080/PIMS/desktop/dateManager/lookDate.jsp");
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