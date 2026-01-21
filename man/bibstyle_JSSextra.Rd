\name{bibstyle_JSSextra}
\alias{bibstyle_JSSextra}

\title{Create bibstyle JSSextra}

\description{

  Get or create bibstyle JSSextra or clones of it for derived bib styles.

}

\usage{
bibstyle_JSSextra(style = "JSSextra", reset = FALSE, make_default = FALSE)
}

\arguments{
  \item{style}{
    the name of the style. The default is \code{"JSSextra"}.
  }
  \item{reset}{
    if \code{TRUE}, create a fresh copy of the style even if it exists.
  }
  \item{make_default}{
    if \code{TRUE}, make the style default.
  }
}
\details{

  \code{bibstyle_JSSextra()} returns the bib style \code{"JSSextra"}
  (i.e., its environment, not the name of the style). If
  \code{"JSSextra"} has not been created yet, it creates it first.

  If argument style is used, as in
  \code{bibstyle_JSSextra("mystyle")}, a style "mystyle" initially
  equivalent to \code{"JSSextra"} is returned (it is created if
  necessary). The returned environment can be amended to derive a new
  bib style.

}
\value{
  an environment
}
\author{Georgi N. Boshnakov}

%\seealso{
%%% ~~objects to See Also as \code{\link{help}}, ~~~
%}

%\examples{
%}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory (show via RShowDoc("KEYWORDS")):
% \keyword{ ~kwd1 }
% \keyword{ ~kwd2 }
% Use only one keyword per line.
% For non-standard keywords, use \concept instead of \keyword:
% \concept{ ~cpt1 }
% \concept{ ~cpt2 }
% Use only one concept per line.
