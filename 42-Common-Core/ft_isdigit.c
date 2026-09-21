/*   By: aabu-jwe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:55:39 by aabu-jwe          #+#    #+#             */
/*   Updated: 2026/09/20 14:00:42 by aabu-jwe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#incldue "libft.h"
int ft_isdigit(int c)
{       
        if (c >= 0 && c <= 9)
        {
                return 1;
        }
        return 0;
}       


