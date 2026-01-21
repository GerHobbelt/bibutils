context("https")

test_that("https is exported, not http", {
    bib <- system.file("bib/Kisung_Rdpack_21.bib", package = "rbibutils")
    bib_Rdpack_21 <- readBib(bib)
                    # could extract the url field also with: bib_Rdpack_21[["example", "url"]]
    expect_true(grepl("https://arxiv.org/abs/1310.8110", bib_Rdpack_21["example"]$url))
})
