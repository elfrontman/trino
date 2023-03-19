<article id="post-<?php the_ID(); ?>" <?php post_class(); ?>>
	<div class="mkdf-post-content">
		<div class="mkdf-post-text">
			<div class="mkdf-post-text-inner">
				<div class="mkdf-post-mark">
					<span aria-hidden="true" class="icon_quotations"></span>
				</div>
				<div class="mkdf-post-info">
					<?php optimize_mikado_post_info(array('date' => 'yes')) ?>
				</div>
				<div class="mkdf-post-title">
					<h3>
						<a href="<?php the_permalink(); ?>" title="<?php the_title_attribute(); ?>"><?php echo esc_html(get_post_meta(get_the_ID(), "mkdf_post_quote_text_meta", true)); ?></a>
					</h3>
					<span class="quote_author">&mdash; <?php the_title(); ?></span>
				</div>
			</div>
			<div class="mkdf-author-desc clearfix">
				<div class="mkdf-image-name">
					<div class="mkdf-author-image">
						<a href="<?php echo esc_url(optimize_mikado_get_author_posts_url()) ?>">
							<?php echo optimize_mikado_kses_img(get_avatar(get_the_author_meta('ID'), 102)); ?>
						</a>
					</div>
					<div class="mkdf-author-name-holder">
						<h5 class="mkdf-author-name">
							<a href="<?php echo esc_url(optimize_mikado_get_author_posts_url()); ?>">
								<span><?php esc_html_e('by', 'optimize'); ?></span>
								<span itemprop="author">
									<?php echo esc_html(optimize_mikado_get_the_author_name()); ?>
								</span>
							</a>
						</h5>
					</div>
				</div>
			</div>
		</div>
	</div>
</article>