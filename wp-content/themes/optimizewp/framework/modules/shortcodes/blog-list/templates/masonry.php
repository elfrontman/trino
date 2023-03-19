<li <?php post_class('mkdf-blog-list-item mkdf-blog-list-masonry-item clearfix'); ?>>
	<div class="mkdf-blog-list-item-inner">
		<?php if(!$hide_image) : ?>
			<div itemprop="image" class="mkdf-item-image">
				<a itemprop="url" href="<?php echo esc_url(get_permalink()) ?>">
					<?php if($use_custom_image_size) : ?>
						<?php echo optimize_mikado_generate_thumbnail(
							get_post_thumbnail_id(get_the_ID()),
							null,
							$custom_image_dimensions[0],
							$custom_image_dimensions[1]
						); ?>
					<?php else: ?>
						<?php the_post_thumbnail($thumb_image_size); ?>
					<?php endif; ?>
				</a>
			</div>
		<?php endif; ?>
		<div class="mkdf-item-text-holder">
			<div class="mkdf-item-date">
				<time itemprop="datePublished" datetime="<?php echo esc_attr(the_time('Y-m-d')); ?>">
					<?php the_time(get_option('date_format')); ?>
				</time>
			</div>
			<<?php echo esc_html($title_tag) ?> itemprop="headline" class="mkdf-item-title">
			<a itemprop="url" href="<?php echo esc_url(get_permalink()) ?>">
				<?php echo esc_attr(get_the_title()) ?>
			</a>
		</<?php echo esc_html($title_tag) ?>>

		<?php if($text_length != '0') {
			$excerpt = ($text_length > 0) ? substr(get_the_excerpt(), 0, intval($text_length)) : get_the_excerpt(); ?>

			<?php if($excerpt !== '') : ?>
				<p itemprop="description" class="mkdf-excerpt"><?php echo esc_html($excerpt) ?></p>
			<?php endif; ?>
		<?php } ?>

		<div class="mkdf-post-item-author-holder">
			<a itemprop="url" href="<?php echo esc_url(optimize_mikado_get_author_posts_url()); ?>">
				<span class="mkdf-post-item-author-avatar-holder">
					<?php echo optimize_mikado_kses_img(get_avatar(get_the_author_meta('ID'), 30)); ?>
				</span>

				<span itemprop="author" class="mkdf-post-item-author-name">
					<?php echo esc_html(optimize_mikado_get_the_author_name()); ?>
				</span>
			</a>
		</div>
	</div>
	</div>
</li>