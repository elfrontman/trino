<li <?php post_class('mkdf-blog-list-item clearfix'); ?>>
	<div class="mkdf-blog-list-item-inner">
		<?php if(has_post_thumbnail()) : ?>
			<div class="mkdf-item-image clearfix" itemprop="image">
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
			<<?php echo esc_html( $title_tag)?> itemprop="headline" class="mkdf-item-title">
				<a itemprop="url" href="<?php echo esc_url(get_permalink()) ?>" >
					<?php echo esc_attr(get_the_title()) ?>
				</a>
			</<?php echo esc_html($title_tag) ?>>

			<?php if ($text_length != '0') {
				$excerpt = ($text_length > 0) ? substr(get_the_excerpt(), 0, intval($text_length)) : get_the_excerpt(); ?>

				<?php if($excerpt !== '') : ?>
					<p itemprop="description" class="mkdf-excerpt"><?php echo esc_html($excerpt)?></p>
				<?php endif; ?>
			<?php } ?>
			<div class="mkdf-item-date">
				<time itemprop="datePublished" datetime="<?php echo esc_attr(the_time('Y-m-d')); ?>">
					<?php the_time(get_option('date_format')); ?>
				</time>
			</div>
		</div>
	</div>	
</li>
