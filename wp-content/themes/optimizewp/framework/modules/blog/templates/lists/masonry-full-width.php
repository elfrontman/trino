<?php optimize_mikado_get_module_template_part('templates/lists/parts/filter', 'blog'); ?>
<div class="mkdf-blog-holder mkdf-blog-type-masonry mkdf-masonry-full-width mkdf-masonry-pagination-<?php echo optimize_mikado_options()->getOptionValue('masonry_pagination'); ?>">
	<div class="mkdf-blog-masonry-grid-sizer"></div>
	<div class="mkdf-blog-masonry-grid-gutter"></div>
	<?php
	if($blog_query->have_posts()) : while ( $blog_query->have_posts() ) : $blog_query->the_post();
		optimize_mikado_get_post_format_html($blog_type);
	endwhile;
	else:
		optimize_mikado_get_module_template_part('templates/parts/no-posts', 'blog');
	endif;
	?>
</div>
<?php
if(optimize_mikado_options()->getOptionValue('pagination') == 'yes') {

	$pagination_type = optimize_mikado_options()->getOptionValue('masonry_pagination');
	if($pagination_type == 'load-more' || $pagination_type == 'infinite-scroll'){
		if(get_next_posts_page_link($blog_query->max_num_pages)){ ?>
			<div class="mkdf-blog-<?php echo esc_attr($pagination_type); ?>-button-holder">
					<span class="mkdf-blog-<?php echo esc_attr($pagination_type); ?>-button" data-rel="<?php echo esc_attr($blog_query->max_num_pages); ?>">
						<?php
						echo optimize_mikado_get_button_html(array(
							'link' => get_next_posts_page_link($blog_query->max_num_pages),
							'text' => 'Show more'
						));
						?>
					</span>
			</div>
		<?php }
	}else {
		optimize_mikado_pagination($blog_query->max_num_pages, $blog_page_range, $paged);
	}
}
?>