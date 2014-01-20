<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.io.*,java.util.*, javax.servlet.*"%>
<%@ page import="javax.servlet.http.*"%>
<%@ page import="org.apache.commons.fileupload.*"%>
<%@ page import="org.apache.commons.fileupload.disk.*"%>
<%@ page import="org.apache.commons.fileupload.servlet.*"%>
<%@ page import="org.apache.commons.io.output.*"%>

<!DOCTYPE html>
<html>
<head>
<title>upload image</title>
</head>
<body>
<%
	// String imgUrl = "http://localhost:8080/YiKangJBQ/img/default_img.png";
	String imgUrl = "http://" + request.getServerName() + ":" + request.getServerPort() 
			+ "/upload/img/default_img.png";
	
	String filePath = "E:\\Program Files\\apache-tomcat-6.0.37\\webapps\\upload_file\\";
	// String filePath = "C:\\apache-tomcat-6.0.35\\webapps\\upload_file\\";
	// String filePath = "/apps/tomcat/tomcat7_8080/webapps/upload_file/";
	
	String folderName = "/upload_file/";
	
	String url = "http://" + request.getServerName() + ":" + request.getServerPort() + folderName;
	
	// Verify the content type
	String contentType = request.getContentType();
	System.out.println("contentType " + contentType);
	if (request.getContentType() != null 
			&& contentType.indexOf("multipart/form-data") >= 0) {
		
		File dir = new File(filePath);
		if( ! dir.exists()){
			System.out.println(filePath);
			dir.mkdir();
		}
		
		File file;
		int maxFileSize = 5000 * 1024;
		int maxMemSize = 5000 * 1024;
		
		DiskFileItemFactory factory = new DiskFileItemFactory();
		// maximum size that will be stored in memory
		factory.setSizeThreshold(maxMemSize);
		// Location to save data that is larger than maxMemSize.
		factory.setRepository(new File("/temp"));

		// Create a new file upload handler
		ServletFileUpload upload = new ServletFileUpload(factory);
		// maximum file size to be uploaded.
		upload.setSizeMax(maxFileSize);
		try {
			// Parse the request to get file items.
			List fileItems = upload.parseRequest(request);

			// Process the uploaded file items
			Iterator i = fileItems.iterator();

			while (i.hasNext()) {
				FileItem fi = (FileItem) i.next();
				if (!fi.isFormField()) {
					// Get the uploaded file parameters
					String fieldName = fi.getFieldName();
					String fileName = fi.getName();
					boolean isInMemory = fi.isInMemory();
					long sizeInBytes = fi.getSize();
					
					// Write the file
					String prefix = System.currentTimeMillis() + "";
					if (fileName.lastIndexOf("\\") >= 0) {
						fileName = prefix + fileName.substring(fileName.lastIndexOf("\\"));
					} else {
						fileName = prefix + fileName.substring(fileName.lastIndexOf("\\") + 1);
					}
					
					file = new File(filePath + fileName);
					fi.write(file);
					
					imgUrl = url + fileName;

					System.out.println(imgUrl);
					System.out.println();
				}
			}
		} catch (Exception ex) {
			System.out.println(ex);
		}
	}
%>

<img  style="width:100px;height:100px;"id="upload_img" src="<%= imgUrl %>"/>
<form action="img.jsp" method="post" enctype="multipart/form-data">
	<input style="width:180px;border:none;background-color:#5E7DAC;" type="file" id="browse" name="file" size="50" />
	<br/>
	<input style="width:50px;height:20px;text-align:center;margin:5px;" type="submit" id="browse_upload" value="上传" />
</form>

</body>
</html>