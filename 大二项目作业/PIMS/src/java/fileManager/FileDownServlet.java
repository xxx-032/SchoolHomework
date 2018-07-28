/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fileManager;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import sun.misc.BASE64Decoder;
import java.net.URLEncoder;
import java.util.ArrayList;
import javax.servlet.http.HttpSession;

/**
 *
 * @author xxx_032
 */
public class FileDownServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
  
        response.setContentType("text/html;charset=utf-8");
        response.setCharacterEncoding("utf-8");
        HttpSession session=request.getSession();
        ArrayList login=(ArrayList)session.getAttribute("login");
        if(login==null||login.size()==0){
            response.sendRedirect("http://localhost:8080/PIMS/login/login.jsp");
        }       
        
        
        try {
            response.setContentType("text/html;charset = utf-8");
            request.setCharacterEncoding("utf-8");
            
            String destinationfileName = request.getParameter("destinationfileName");
            // 得到要下载的文件的所在目录，同上，小伙伴可以根据自己项目更改内容
            String uploadpath = request.getParameter("uploadPath");

            // 得到要下载的文件
            File file = new File(uploadpath + "\\" + destinationfileName);

            //如果文件不存在，则显示下载失败
            if (!file.exists()) {

                return;
            } else {

                // 设置相应头，控制浏览器下载该文件，这里就是会出现当你点击下载后，出现的下载地址框
                response.setHeader("content-disposition",
                        "attachment;filename=" + URLEncoder.encode(destinationfileName, "utf-8"));
                // 读取要下载的文件，保存到文件输入流
                FileInputStream in = new FileInputStream(uploadpath + "\\" + destinationfileName);
                // 创建输出流
                OutputStream out = response.getOutputStream();
                // 创建缓冲区
                byte buffer[] = new byte[1024];
                int len = 0;
                // 循环将输入流中的内容读取到缓冲区中
                while ((len = in.read(buffer)) > 0) {
                    // 输出缓冲区内容到浏览器，实现文件下载
                    out.write(buffer, 0, len);
                }
                // 关闭文件流
                in.close();
                // 关闭输出流
                out.close();
                response.sendRedirect("http://localhost:8080/PIMS/lookFileServlet");
            }
        } catch (Exception e) {
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
