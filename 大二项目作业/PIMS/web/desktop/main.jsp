<%-- 
    Document   : main
    Created on : 2018-6-19, 21:37:51
    Author     : xxx_032
--%>

<%@page import="loginRegister.localUser"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Welcome to MyPIMS</title>
<meta name="keywords" content="" />
<meta name="description" content="" />

    <link href="http://localhost:8080/PIMS/desktop/css/tooplate_style.css" rel="stylesheet" type="text/css" />

    <link rel="stylesheet" link href="http://localhost:8080/PIMS/desktop/css/galleriffic-2.css" type="text/css" />

	<script type="text/javascript" src="js/jquery-1.3.2.js"></script>
    <script type="text/javascript" src="js/jquery.galleriffic.js"></script>
    
    <script type="text/javascript" src="js/jquery.opacityrollover.js"></script>
    <!-- We only want the thunbnails to display when javascript is disabled -->
    <script type="text/javascript">
    document.write('<style>.noscript { display: none; }</style>');
    </script>
    
</head>
<body id="home">
<div id="tooplate_wrapper">
    <div id="tooplate_header">
        <div id="tooplate_menu">

            <ul>
                <li><a href="http://localhost:8080/PIMS/desktop/main.jsp" class="current"><span></span>Home</a></li>
                <li><a href="http://localhost:8080/PIMS/LookMessageServlet?userName=<%=localUser.username%>"><span></span>About yourself</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/List.jsp"><span></span>List</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/Plan.jsp"><span></span>Plan</a></li>
                <li><a href="http://localhost:8080/PIMS/desktop/File.jsp"><span></span>File</a></li>
                <li><a href="http://localhost:8080/PIMS/login/login.jsp"><span></span>Exit</a></li>
            </ul>    	
        </div> <!-- end of tooplate_menu -->
        
        <div id="site_title"><h1><a href="#">My PIMS WebSite</a></h1></div>
        
        <div id="tooplate_slider">
    	
        	<!-- Start Advanced Gallery Html Containers -->
				<div id="gallery" class="content">
					<div class="slideshow-container">
						<div id="loading" class="loader"></div>
						<div id="slideshow" class="slideshow"></div>
					</div>
				</div>
				<div id="thumbs" class="navigation">
					<ul class="thumbs noscript">
						<li>
							<a class="thumb" name="leaf" href="images/slider/01_l.jpg" title="Title 01">
								<img src="images/slider/01_t.jpg" alt="Title 01" />
							</a>
						</li>

						<li>
							<a class="thumb" name="leaf" href="images/slider/02_l.jpg" title="Title 02">
								<img src="images/slider/02_t.jpg" alt="Title 02" />
							</a>
						</li>
                        
                        <li>
							<a class="thumb" name="leaf" href="images/slider/03_l.jpg" title="Title 03">
								<img src="images/slider/03_t.jpg" alt="Title 03" />
							</a>
						</li>
                        
                        <li>
							<a class="thumb" name="leaf" href="images/slider/04_l.jpg" title="Title 04">
								<img src="images/slider/04_t.jpg" alt="Title 04" />
							</a>
						</li>
                        
                        <li>
							<a class="thumb" name="leaf" href="images/slider/05_l.jpg" title="Title 05">
								<img src="images/slider/05_t.jpg" alt="Title 05" />
							</a>
						</li>
					</ul>
				</div>
	    </div>
    </div> <!-- end of header -->
    

    
</div> <!-- end of wrapper -->
<div id="tooplate_footer_wrapper">
    <div id="tooplate_footer">
        Copyright © 2018 Create by cmj.
        <div class="cleaner"></div>
    </div>
</div>    

		<script type="text/javascript">
			jQuery(document).ready(function($) {
				// We only want these styles applied when javascript is enabled
				$('div.navigation').css({'width' : '960px', 'float' : 'left'});
				$('div.content').css('display', 'block');

				// Initially set opacity on thumbs and add
				// additional styling for hover effect on thumbs
				var onMouseOutOpacity = 0.67;
				$('#thumbs ul.thumbs li').opacityrollover({
					mouseOutOpacity:   onMouseOutOpacity,
					mouseOverOpacity:  1.0,
					fadeSpeed:         'fast',
					exemptionSelector: '.selected'
				});
				
				// Initialize Advanced Galleriffic Gallery
				var gallery = $('#thumbs').galleriffic({
					delay:                     2500,
					numThumbs:                 5,
					preloadAhead:              10,
					enableTopPager:            false,
					enableBottomPager:         false,
					maxPagesToShow:            7,
					imageContainerSel:         '#slideshow',
					controlsContainerSel:      '#controls',
					captionContainerSel:       '#caption',
					loadingContainerSel:       '#loading',
					renderSSControls:          true,
					renderNavControls:         true,
					playLinkText:              'Play Slideshow',
					pauseLinkText:             'Pause Slideshow',
					prevLinkText:              '&lsaquo; Previous Photo',
					nextLinkText:              'Next Photo &rsaquo;',
					nextPageLinkText:          'Next &rsaquo;',
					prevPageLinkText:          '&lsaquo; Prev',
					enableHistory:             false,
					autoStart:                 false,
					syncTransitions:           true,
					defaultTransitionDuration: 900,
					onSlideChange:             function(prevIndex, nextIndex) {
						// 'this' refers to the gallery, which is an extension of $('#thumbs')
						this.find('ul.thumbs').children()
							.eq(prevIndex).fadeTo('fast', onMouseOutOpacity).end()
							.eq(nextIndex).fadeTo('fast', 1.0);
					},
					onPageTransitionOut:       function(callback) {
						this.fadeTo('fast', 0.0, callback);
					},
					onPageTransitionIn:        function() {
						this.fadeTo('fast', 1.0);
					}
				});
			});
		</script>
</body>
</html>
