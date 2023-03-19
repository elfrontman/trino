<li <?php post_class('mkdf-blog-list-item clearfix'); ?>>
	<div class="mkdf-blog-list-item-inner">
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
