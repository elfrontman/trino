<article class="mkdf-portfolio-item <?php echo esc_attr($article_masonry_size)?> <?php echo esc_attr($categories)?>">
	<a class ="mkdf-portfolio-link" href="<?php echo esc_url($item_link); ?>"></a>
	<div class = "mkdf-item-image-holder">
	<?php
		echo get_the_post_thumbnail(get_the_ID(),$thumb_size);
	?>				
	</div>
	<div class="mkdf-item-text-overlay">
		<div class="mkdf-item-text-overlay-inner">
			<div class="mkdf-item-text-holder">
				<<?php echo esc_attr($title_tag)?> class="mkdf-item-title">
					<?php echo esc_attr(get_the_title()); ?>
				</<?php echo esc_attr($title_tag)?>>	
				<?php 
				echo $icon_html; 
				echo $category_html;
				?>
			</div>
		</div>	
	</div>
</article>
